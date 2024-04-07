// 6.NFA that display the string starting with 10 or not over (0,1}.

#include <stdio.h>
#include <string.h>

char input[20];
int l;
int flag;

// Transition functions for the NFA
void s(int i)
{
    flag = 1; // Accepting state
}

void r(int i)
{
    if (i < l)
    {
        if (input[i] == '1')
        {
            ++i;
            s(i);
        }
    }
}

void q(int i)
{
    if (i < l)
    {
        if (input[i] == '0')
        {
            ++i;
            r(i);
        }
    }
}

void p(int i)
{
    if (i < l)
    {
        int k = i;
        if (input[i] == '1')
        {
            k++;
            p(k);
            q(k);
        }
        else if (input[i] == '0')
        {
            i++;
            p(i);
        }
    }
}

int main()
{
    printf("\nEnter a binary string: ");
    scanf("%s", input);

    l = strlen(input);
    int i = 0;
    flag = 0;

    // Check if string starts with "10" or parse using NFA
    if (l >= 2 && input[0] == '1' && input[1] == '0')
    {
        p(i); // Start parsing the string
    }

    if (flag == 1)
        printf("\nThe string is accepted.\n");
    else
        printf("\nThe string is not accepted.\n");

    return 0;
}