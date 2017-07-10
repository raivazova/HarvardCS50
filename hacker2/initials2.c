/*
 *
 * @Ralitsa Ayvazova@
 *
 * raivazova@gmail.com
 *
 *
 * Asks for the users full name
 * and prints out his/hers initials
 *
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void print_initials(char x);
 
int main(int argc, string argv[])
{
    
   
    // Gets the user's name
    
    argv[1] = GetString();
    //gets the lenght of the string
    int string_size = strlen(argv[1]);
    
    // for every character of the string
    for (int i = 0; i < string_size; i++)
    {
        // if it is alphabetic
        if (isalpha(argv[1][i]))
        {
            // and the one before was not alphabetic
            if ( !isalpha(argv[1][i - 1]))
            {
                // prints the current one
                print_initials(argv[1][i]);
            }
            
        }
        else
        // if currrent character not alphabetic
        {
            // but the one after is alphabetic
            if ( isalpha(argv[1][i + 1]))
            {
                // prints the one after the nonalphabetic one
                i++;
                print_initials(argv[1][i]);
                
            }
        }
        
        
    }
    printf("\n");
}
 
 
 // function that prints out initials out of a name
        
 void print_initials(char x)
 {
     
      // checks if is  upper case and prints if it is
      if (x >= 65 && x <= 90)
      {
            printf("%c", x);
      }
      else
      {
            // else switches it to upper case and then prints it
            x = x - 32;
            printf("%c", x);
      }
 };    
