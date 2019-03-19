#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);
void pyramid(int n);
void dots(int k);

int main(void)
{
    int height = get_positive_int("Height (from 1 to 8 inclusive): ");
//     printf("%i\n", height);
    pyramid(height);
}

// Prompt user for positive integer
int get_positive_int(string prompt)
{
    int num;
    do
    {
        num = get_int("%s", prompt);
    }
    while (num < 1 || num > 8);
    return num;
}

void pyramid(int n)
{
//     for (int i = 0; i < n; i++)
//     {
//         printf("#\n");
//     }
    
    for (int i = 0; i < n; i++)
    {
//         printf(".");
        dots(n - i - 1);
        for (int j = 0; j <= i; j++)
        {
//             dots(n - i - 1);
            printf("#");
//             printf(" i = %i", i);
//             printf(" j = %i", j);
        }
        printf("\n");
    }    
}

void dots(int k)
{
    for (int i = 0; i < k; i++)
    {
        printf(" ");
    }        
}

