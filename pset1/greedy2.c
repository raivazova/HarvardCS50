/*
 *
 * @Ralitsa Ayvazova@
 *
 * raivazova@gmail.com
 *
 * a program that first asks the user how much change is owed 
 * 
 * and then spits out the minimum number of coins 
 * 
 * with which said change can be made
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
     * How much is the owed change?
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
    
    // devide by a quarter to check how mane we can use
    int quarters = cents / 25;
    // use modulo to take the remaining value
    int reminder = cents % 25;
    
    // adding the used quarters to UsedCoins
    UsedCoins = UsedCoins + quarters;
    
    // devide by a dime to check how mane we can use
    int dimes = reminder / 10;
    // use modulo to take the remaining value
    reminder = reminder % 10;
    
    // adding the used dimes to UsedCoins
    UsedCoins = UsedCoins + dimes;
    
    // devide by a nicle to check how mane we can use
    int nicles = reminder / 5;
    // use modulo to take the remaining value
    reminder = reminder % 5;
    
    // adding the used nicles to UsedCoins
    UsedCoins = UsedCoins + nicles;
  
     // devide by a pennie to check how mane we can use
    int pennies = reminder / 1;
    // use modulo to take the remaining value
    reminder = reminder % 1;
    
    // adding the used pennies to UsedCoins
    UsedCoins = UsedCoins +  pennies;
    
    
    // if there are no coins left print the number of used coins
     if (reminder == 0)
    {
        printf("%i\n", UsedCoins);
    }  
}
    

    
