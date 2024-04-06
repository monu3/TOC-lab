// PDA

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isAnBn(const string &input)
{
    stack<char> stack;

    bool bEncountered = false; // Flag to track if 'b' has been encountered

    for (char c : input)
    {
        if (c == 'a')
        {
            if (bEncountered)
            {
                return false; // If 'a' is encountered after 'b', reject the string
            }
            stack.push('a');
        }
        else if (c == 'b')
        {
            bEncountered = true;
            if (stack.empty() || stack.top() != 'a')
            {
                return false; // More 'b's than 'a's or 'b' before any 'a'
            }
            stack.pop(); // Match 'a' with 'b'
        }
        else
        {
            return false; // Invalid character
        }
    }

    return stack.empty() && bEncountered; // Stack should be empty and 'b' should be encountered
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isAnBn(input))
    {
        cout << "The string \"" << input << "\" belongs to the language L={anbn:n≥1}." << endl;
    }
    else
    {
        cout << "The string \"" << input << "\" does not belong to the language L={anbn:n≥1}." << endl;
    }

    return 0;
}
