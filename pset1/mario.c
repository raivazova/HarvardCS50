/*
 *
 * @raivazova
 *
 * This is a program that prints out a half-pyramid alligned to the right 
 *
 * The half-pyramid has as many lines as the user inputs 
 *
 * The input must be a non-negative integer no greater than  23
 *
 *
 */
 
#include <stdio.h>
#include <cs50.h>


/* 
 *Function that when it's called prints the requiered number of spaces
 *
 */

void PrintSpace(int hight, int i)
{
    // on the first line prints as many spaces as the user input is minus one
    // and then one less on each line
    for(int j = 0; (j < hight - (i + 1)); j++)
    {
        printf(" ");
    }
    
}

/* 
 *Function that when it's called prints the requiered number of hashes
 *
 */
void PrintHash(int i)
{
    // on the first line prints two hashes, and then one more on each line
    for(int k = 0; (k < (i + 2)); k++)
    {
        printf("#");   
    }
    
}



int main(void)
{
    int hight;
    
    /*
     * Asks the user how high the pyramid should be
     */
    do
    {
        printf("Enter a non-negative integer no greater than 23:\n");
        hight = GetInt();
    }
    while (hight < 0 || hight >= 24);
    
    
    /*
     *Building a half-pyramid according to the user's input
     */  
    for(int i = 0; i < hight; i++)
    {
        PrintSpace(hight, i);
        PrintHash(i);
        printf("\n");
       
    }
}
