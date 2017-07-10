/*
 *
 * @Ralitsa Ayvazova@
 *
 * raivazova@gmail.com
 *
 *
 * prints out person's initials
 * after the have inputed their name in the command line
 *
 */

#include <cs50.h>
#include <stdio.h>



int main(int argc, string name[])
{
    
   
   
   // checks if the first character of each name is upper case
    for (int i = 0;i < argc; i++)
    {
        if (name[i][0] >= 65 && name[i][0] <= 90)
        {
            printf("%c", name[0][i]);
        }
        else
        // if lower case swich to upper and print
        {
            name[i][0] = name[i][0] - 32;
            printf("%c", name[i][0]);
        }
    }
    printf("%i\n", argc);
}
