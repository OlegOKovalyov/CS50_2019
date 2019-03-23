#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_positive_int(string prompt);

int main(int argc, string argv[])
{
    if (argc != 2 || !isdigit(argv[1][0]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    
    int key = atoi(argv[1]);
    string s = get_string("plaintext: ");
    int n = strlen(s);
    
    printf("ciphertext: ");
    for (int i = 0; i < n; ++i)
    {
        if ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') )
        {
            if (islower(s[i])) 
            {
                printf( "%c", ((s[i] + key) - 'a') % 26 + 'a'  );
            }
            else if (isupper(s[i]))
            {
                printf( "%c", ((s[i] + key) - 'A') % 26 + 'A'  );
            }
        }
        else 
        {
            printf( "%c", s[i] );
        }
    }
    printf("\n");
}

// Prompt user for positive integer
int get_positive_int(string prompt)
{
    int num;
    do
    {
        num = get_int("%s", prompt);
    }
    while (num < 1);
    return num;
}
