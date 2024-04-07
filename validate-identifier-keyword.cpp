// validate identifier and keyword
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main()
{
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    // Check if first character is a letter or underscore
    if (!(isalpha(str[0]) || str[0] == '_'))
    {
        cout << "Invalid identifier" << endl;
        return 0;
    }

    int len = strlen(str);
    // Check if remaining characters are letters, digits or underscore
    for (int i = 1; i < len; ++i)
    {
        if (!(isalnum(str[i]) || str[i] == '_'))
        {
            cout << "Invalid identifier" << endl;
            return 0;
        }
    }

    // Manually initialize set with keywords
    set<string> keywords;
    keywords.insert("auto");
    keywords.insert("break");
    keywords.insert("case");
    // Add other keywords similarly...

    // Check if string is a keyword
    if (keywords.find(str) != keywords.end())
    {
        cout << "Keyword" << endl;
    }
    else
    {
        cout << "Valid identifier" << endl;
    }

    return 0;
}