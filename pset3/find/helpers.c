/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"


/**
 * swaps two values in an array
 */
void swap(int* x, int* y);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    
    if (value < 0)
    {
        return false;
    }
    int leftBound = 0;
    int rightBound = n - 1;
    while(leftBound <= rightBound)
    {
       
        int middle = (leftBound + rightBound) / 2;
    
        if(values[middle] > value)
        {                  
            rightBound = middle - 1;              
        }
        else if(values[middle] < value)
        {
            leftBound = middle + 1;
        }
        else if(values[middle] == value)
        {
           return true;
        }
            
     }
         
   return false; 
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int swaps;
    int k = n - 1;
    do
    {
        swaps = 0;
        
        for (int i = 0; i < k; i++)
        {
            if (values[i] > values[i + 1])
            {
                swap(&values[i], &values[i + 1]);
                
                swaps++;
            } 
            
        }
        k--; 
    }
    while(swaps != 0);
    
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;  
    
}
