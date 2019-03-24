#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s keyword\n", argv[0]);
        return 1;
    }
    else 
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: %s keyword\n", argv[0]);
                return 1;
            }    
        }
    }
    
    
    string keyword = argv[1];
    int k = strlen(keyword);
    string s = get_string("plaintext: ");
    int n = strlen(s);
    
    printf("ciphertext: ");
    for (int i = 0, j = 0; i < n; i++)
    {
        if ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') )
        {
            int key = tolower(keyword[j % k]) - 'a';
            if (islower(s[i])) 
            {
                printf( "%c", ((s[i] + key) - 'a') % 26 + 'a'  );
                j++;
            }
            else if (isupper(s[i]))
            {
                printf( "%c", ((s[i] + key) - 'A') % 26 + 'A'  );
                j++;
            }
        }
        else 
        {
            printf( "%c", s[i] );
        }            
    }
    printf("\n");
    return 0;
}
