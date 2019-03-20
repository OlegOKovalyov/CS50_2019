#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_positive_float(string prompt);

int main(void)
{
    int res = 0;
    float dollars = get_positive_float("Your change: ");
    int coins = round(dollars * 100);
    if (coins >= 25)
    {
        res = coins / 25;
        coins = coins % 25;
    }
    if (coins >= 10)
    {
        res = res + coins / 10;
        coins = coins % 10;
    }
    if (coins >= 5)
    {
        res = res + coins / 5;
        coins = coins % 5;
    }
    res = res + coins;
    printf("%i\n", res);
}

// Prompt user for positive float
float get_positive_float(string prompt)
{
    float num;
    do
    {
        num = get_float("%s", prompt);
    }
    while (num < 0);
    return num;
}