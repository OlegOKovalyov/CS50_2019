#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);
void pyramid(int n);
void spaces(int k);

int main(void)
{
    int height = get_positive_int("Height (from 1 to 8 inclusive): ");
    pyramid(height);
}

// Prompt user for positive integer from 1 to 8 iclusive
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

// Output Mario's pyramid on the screen
void pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        spaces(n - i - 1);
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }    
}

// Add spaces before '#'
void spaces(int k)
{
    for (int i = 0; i < k; i++)
    {
        printf(" ");
    }        
}