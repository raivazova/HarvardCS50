/*
 *
 * @Ralitsa Ayvazova@
 *
 * raivazova@gmail.com
 *
 *
 * prints out person's initials
 * after the have inputed their name 
 *
 */
#include <stdio.h>
#include <cs50.h>
#include <string.h>
 
 
int main(void)
{
    string full_name;
   
    // Gets the user's name
    
    full_name = GetString();
    
    
    // checks if the first letter is  upper case
    // and prints it if it is
    if (full_name[0] >= 65 && full_name[0] <= 90)
    {
        printf("%c", full_name[0]);
    }
    else
    // if lower case swich to upper and print
    {
        full_name[0] = full_name[0] - 32;
        printf("%c", full_name[0]);
    }
        
    int string_size = strlen(full_name);
    
    for (int i = 0; i < string_size; i++)
    {
        // searching for the "space" between the names
        
        if (full_name[i] == 32)
        {
            // prints the first character after the "space"
            // if it is an upper case letter
            i++;
            if (full_name[i] >= 65 && full_name[i] <= 90)
            {
                printf("%c", full_name[i]);
            }
            else
            {
                // else switches it to upper case and then prints it
                full_name[i] = full_name[i] - 32;
                printf("%c", full_name[i]);
            } 
        }
     }
    printf("\n");
}
 
 

