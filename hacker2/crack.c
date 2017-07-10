#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <unistd.h>

FILE *dictionary;

int main(int argc, string argv[])
{
    // checks for input of a key after the name of the program
    if (argc != 2)
    {
        printf("Usage: ./crack <encrypted password>\n");
        return 1;
    }
    
    
    
    char salt[] = {argv[1][0], argv[1][1]};
    
    
    char line[1024];
    dictionary = fopen("/usr/share/dict/words", "r");
    if ((dictionary = fopen("/usr/share/dict/words", "r")) == NULL)
     { /* Open source file. */
        printf("error fopen source-file\n");
        return 1;
     }
    while(fgets(line, sizeof(line), dictionary) != NULL)
    {
        char *crypt(const char *line, const char *salt);
        if(*crypt == argv[1])
        {
            line[strlen(line) - 1] = '\0';
            printf("%s\n", line);
        }
    }
    fclose(dictionary);
    
    
 
 
 
 
 
 
 
 
 
 
 
    
}

