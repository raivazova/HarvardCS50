/*
 *
 * @Ralitsa Ayvazova@
 *
 * raivazova@gmail.com
 *
 * a program that first asks the user how much change is owed 
 * 
 * and then spits out the minimum number of coins with
 * 
 * which said change can be made
 * 
 * using a greedy algorithm
 * 
 */
#include <stdio.h>
#include <cs50.h>
#include <math.h>



int main(void)
{
    float change;
    
    /*
     * Asks for the user's input
     *
     * How much is the owed change ?
     *
     */
 
    do
    {
        printf("Enter a non-negative value of change in dollars:\n");
        change = GetFloat();
    }
    // It must be a non-negative value
    while (change <= 0);
    
    // Converting the dollars value into cents 
    // By multiplying by 100 and rounding to the nearest integer
    float ToCents = change * 100.00;
    int cents = round(ToCents);
    
    // A variable counting the used coins
    int UsedCoins = 0;
    
    // Checking if we can use a quarter
    // If yes incrementig NumOfCoins by 1
    while (cents >= 25)
    {
        UsedCoins++;
        cents = cents - 25;
    }
    
   
    
    // Checking if we can use a dime
    // If yes incrementig NumOfCoins by 1
    while (cents >= 10)
    {
        UsedCoins++;
        cents = cents - 10;
    }
    
   
    // Checking if we can use a nicle
    // If yes incrementig NumOfCoins by 1
    while (cents >= 5)
    {
        UsedCoins++;
        cents = cents - 5;
    }
    
  
    // Checking if we can use a pennie
    // If yes incrementig NumOfCoins by 1    
    while (cents >= 1)
    {
        UsedCoins++;
        cents = cents - 1;
    }
    
    
    // If there are no cents left print the count of coins used    
    if (cents == 0)
    {
        printf("%i\n", UsedCoins);
    }  
}
