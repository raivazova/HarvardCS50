/*
 *
 * @Ralitsa Ayvazova@
 *
 * raivazova@gmail.com
 *
 * Checking if credit card number is fraudulent
 */
 
#include <stdio.h>
#include <cs50.h>

int main(void)
{
   
    long long CardNumber = 0, temp = 0, factor = 1;
    int CheckCard[16];
    int i = 0;
    int count = 0;
 
    
   
// Asking the user for input
    printf("Please enter your card number:\n");
    CardNumber = GetLongLong();
    
    temp = CardNumber;
// checking how many digits in the number
    while(temp)
    {
        temp = temp / 10;
        count++;
        factor = factor * 10;
    }
    
// transferring the long long number into array
    while(factor > 1)
    {
        
        factor = factor / 10;
        CheckCard[i] = CardNumber / factor;
        CardNumber = CardNumber % factor;
        i++;
    }
   
// identifying from which element to start to multiply
// depending of the number of digits
    int j;
    int ToMultiply = 0;
    
    if (count == 15)
    {
        j = 13;
        ToMultiply = 7; 
    }
    else if ( count == 13)
    {
        j = 11;
        ToMultiply = 6;
    }
    else if (count == 16)
    {
        j = 14;
        ToMultiply = 8;
    }
    
// creating an array to store the multiplied numbers
    int mult[16];
    
// multiplying every other digit of the array by 2
// starting from the second to the last
    for(i = 0;i < ToMultiply;i++)
    {
        int num = CheckCard[j];
        num = num * 2;
        mult[i] = num;
        j = j - 2;
    }
    
    
    int position = ToMultiply;

    for(i = 0; i < ToMultiply; i++)
    {  
        int CountDigits = 0;
        
        
        int CurrentNum = mult[i];
        temp = CurrentNum;
        
// counting how many digits in each element of the array
        while (temp)
        {
            temp = temp / 10;
            CountDigits++;
        }
        
 
// if digits >1 moving the hundrets to the first available position of mult[]
        if (CountDigits > 1)
        {
            mult[i] = CurrentNum / 10;
            mult[position] = CurrentNum % 10;
            
                
            position++;
        }
        
    }
   
    int Sum1 = 0;
    int Sum2 = 0;
// the sum of the multiplied numbers
    for (i = 0; i < position; i = i + 2)
    {
        Sum1 = Sum1 + mult[i] + mult[i + 1];
    }
    
// the sum of the digits that weren't multiplied
    if (count == 16)
    {
        for(i = 1; i <= count; i = i + 4)
        {
            Sum2 = Sum2 + CheckCard[i] + CheckCard[i + 2]; 
        }
    }
    else
    {
        for(i = 0; i < count; i = i + 4)
        {
            Sum2 = Sum2 + CheckCard[i] + CheckCard[i + 2]; 
        }
    }
// and everything together..
    int CheckSum = Sum1 + Sum2;
    
// check if the total last digit is 0
    if (CheckSum % 10 == 0 )
    {
// check if the first two digits corespond to AMEX or Mastercard
        if (CheckCard[0] == 3 && (CheckCard[1] == 4 || CheckCard[1] == 7) && count == 15)
        {
            printf("AMEX\n");
        }
        else if (CheckCard[0] == 5 && (CheckCard[1] == 1 || CheckCard[1] == 2 || CheckCard[1] == 3 || CheckCard[1] == 4 || CheckCard[1] == 5) && count == 16)
        {
            printf("MASTERCARD\n");
        }
        // checking if the first digit coresponds to visa
        else if (CheckCard[0] == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
    }
    else 
    // if the last digit of te total is not 0
    // the card is invalid
    {
        printf ("INVALID\n");
    }
    
}
