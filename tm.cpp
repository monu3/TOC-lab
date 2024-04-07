// Design a TM  that accepts L= {anbn / n ≥ 1}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool simulateTM(string tape)
{
    int head = 0;
    while (true)
    {
        // Step 1: Find the first 'a' and mark it as read ('X')
        head = 0;
        while (head < tape.length() && tape[head] != '0')
        {
            head++;
        }
        if (head == tape.length())
        {
            // If no 'a' is found, check if all 'b's are marked and end of tape is reached
            for (char c : tape)
            {
                if (c == '1')
                    return false; // Unmarked 'b' found, reject
            }
            return true; // All symbols are correctly marked, accept
        }
        tape[head] = 'X'; // Mark the 'a'

        // Step 2: Move right to find and mark the corresponding 'b' ('Y')
        while (head < tape.length() && tape[head] != '1')
        {
            head++;
        }
        if (head == tape.length())
            return false; // Corresponding 'b' not found, reject
        tape[head] = 'Y'; // Mark the 'b'
    }
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (simulateTM(input))
    {
        cout << "String accepted." << endl;
    }
    else
    {
        cout << "String rejected." << endl;
    }

    return 0;
}
