#include <cs50.h>
#include <stdio.h>
#include <math.h>

long int get_positive_long(string prompt);
long int num_size(long int num);
int duplcnter(int rank, int dupls);
int luhn_algorithm (long int cardn);

int main(void)
{

    long int cardnum = get_positive_long("Card Number: ");
    int digits = num_size(cardnum);
    
    if (!luhn_algorithm(cardnum) && (digits == 15))
    {
        int first2 = cardnum / pow(10, 13);
        if ((first2 == 34) || (first2 == 37))
        {
                printf("AMEX\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    else if (!luhn_algorithm(cardnum) && (digits == 16))
    {
        int first1 = cardnum / pow(10, 15);
        int first2 = cardnum / pow(10, 14);
        if ((digits == 16) && ((first2 == 51) || (first2 == 52) || (first2 == 53) || (first2 == 54) || (first2 == 55)))
        {
                printf("MASTERCARD\n");
        }
        else if (first1 == 4) 
        {
            printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    else if (!luhn_algorithm(cardnum) && (digits == 13)) 
    {
        int first1v = cardnum / pow(10, 12);
        if (first1v == 4) 
        {
            printf("VISA\n");
        }        
    }
    else {
        printf("INVALID\n");
    }
}

// Prompt user for long int
long int get_positive_long(string prompt)
{
    long int num;
    do
    {
        num = get_long("%s", prompt);
    }
    while (num < 0);
    return num;
}

long int num_size(long int num)
{
    int i = 0; 
    while (num > 0)
    { 
        num = num / 10;
        i++;
    }
    return i;
}

// Sum of card number digits the next but one multiplying by 2
int duplcnter(int rank, int dupls)
{
    int dupl = rank * 2;
    if (dupl > 9)
    {
        int dupl0 = dupl % 10;
        int dupl1 = dupl / 10 % 10;
        dupls = dupls + dupl0 + dupl1;
    }
    if (dupl < 10)
    {
        dupls = dupls + dupl;
    }
    return dupls;
}

// Luhn's Algorithm
int luhn_algorithm (long int cardn)
{
    int counter = 0;
    int duplsum = 0;
    while (cardn > 0)
    {
        counter++;
        int decade = cardn % 10;
        cardn /= 10;
        if (counter % 2 == 0)
        {
            duplsum = duplcnter(decade, duplsum);
        }
        else {
            duplsum = duplsum + decade;
        }
    }
    
    if (duplsum % 10 == 0)
    {
        return 0;
    }
    return 1;
}
