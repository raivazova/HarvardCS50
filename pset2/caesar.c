/*
 *
 * @Ralitsa Ayvazova@
 *
 * raivazova@gmail.com
 *
 *
 * enciphers a text via caesar cipher 
 * needs a comand line input of a key(integer) for the cipher
 * then prompts the user for input
 * and ciphers their input 
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // checks for input of a key after the name of the program
    if (argc != 2)
    {
        printf("Usage: ./caesar <key>\n./");
        return 1;
    }
    // gets the text to be enciphered
    argv[2] = GetString();
    // gets the lenght of the inputted string
    int lenght = strlen(argv[2]);
    // converts the key into integer
    int key = atoi(argv[1]);
    
    // checks every character of the string
    for (int i = 0; i < lenght; i++)
    {
        // checks if it's a letter of the alphabet
        if (isalpha(argv[2][i]))
        {
            // checks if it's uppercase
            if (isupper(argv[2][i]))
            {
              
                // ciphers the text by the key
                argv[2][i] = (((argv[2][i] - 65) + key) % 26) + 65; 
                
                
            }
            // checks if it's lowercase
            else if (islower(argv[2][i]))
            {
                
                // ciphers the text by the key
                argv[2][i] = (((argv[2][i] - 97) + key) % 26) + 97; 
                
            }
        }
    }
    
    // prints the enciphered string.
    printf("%s\n", argv[2]);

}
