/*
 *
 * @Ralitsa Ayvazova@
 *
 * raivazova@gmail.com
 *
 *
 * encipher a text via vigenere cipher 
 * needs a comand line input of a keyword(strictly alphabetical) for the cipher
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
        printf("Usage: ./caesar <key word>\n");
        return 1;
    }
    // checks if the key word has only alphabetical characters
    // gets the lenght of the key word
    int key = strlen(argv[1]);
    for (int i = 0; i < key; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar <keyword>\n./");
            return 1;
        }
    }
    // gets the text to be enciphered
    argv[2] = GetString();
    // gets the lenght of the inputted string
    int lenght = strlen(argv[2]);
    
    
    
    // checks every character of the string
    for (int i = 0; i < lenght; i++)
    {
        // makes sure that the keyword's characters
        // only switch when the character of the string is alphabetical
        int j = i;
        for (int k = 0; k < i; k++)
        {
            
            if (!isalpha(argv[2][k]))
            {
                j--;
            }
            
        }
        // wrap arround the keyword
        j = j % key;
        
        // checks if the current character of the string 
        // is a letter of the alphabet
        if (isalpha(argv[2][i]))
        {
            // checks if the current character of the string 
            // is uppercase letter
            if (isupper(argv[2][i]))
            {
                // checks if the current character of the keyword 
                // is uppercase letter
                if (isupper(argv[1][j]))
                {
                    // encipher the text by the keyword
                    argv[2][i] = (argv[2][i] - 65) + (argv[1][j] - 65);
                    argv[2][i] = (argv[2][i] % 26) + 65;
                } 
                // checks if the current character of the keyword 
                // is lowercase letter
                else if (islower(argv[1][j]))
                {
                    // encipher the text by the keyword
                    argv[2][i] = (argv[2][i] - 65) + (argv[1][j] - 97);
                    argv[2][i] = (argv[2][i] % 26) + 65;
                }
                
            }
            // checks if the current character of the string 
            // is lowercase letter
            else if (islower(argv[2][i]))
            {
                // checks if the current character of the keyword 
                // is uppercase letter
                if (isupper(argv[1][j]))
                {
                    // encipher the text by the keyword
                    argv[2][i] = (argv[2][i] - 97) + (argv[1][j] - 65);
                    argv[2][i] = (argv[2][i] % 26) + 97;
                } 
                // checks if the current character of the keyword 
                // is lowercase letter
                else if (islower(argv[1][j]))
                {
                    // encipher the text by the keyword
                    argv[2][i] = (argv[2][i] - 97) + (argv[1][j] - 97);
                    argv[2][i] = (argv[2][i] % 26) + 97; 
                }
            }
        }
        
    }
    
    // prints the enciphered string.
    printf("%s\n", argv[2]);

}

