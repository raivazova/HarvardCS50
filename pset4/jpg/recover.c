/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
// initiliazing buffer
char buffer[512];
// the first 4 bytes of jpg
char firstBytes[] = {0xff, 0xd8, 0xff, 0xe0, 0xe1};

// declaring a function
int foundjpg();

int main(int argc, char* argv[])
{
    
    // open the memory card
    FILE* card = fopen("card.raw", "r");
    // if problem opening return error
    if(card == NULL)
    {
        printf("Couldn't open card.raw\n");
        return 2;
    }
    // initiliazing counter variable for jpg titles
    int i = 0;
    // initiliazing variable storing the jpg titles
    char title[10];
    int first = 0;
    
    // initiliaze new img file
    FILE* img = NULL;
    
    // repeat until EO card
    while(fread(&buffer, 512, 1, card) == 1)
    {
       // looking for the first jpg
       if (foundjpg() == 1)
        {
            first = 1;
        }
        
        // after the first jpg is found
        if (first == 1)
        {
            // when new jpg is found
            if(foundjpg() == 1)
            {
                // if there is an open jpg - close it
                if(img != NULL)
                {
                    fclose (img);
                    i++;
                }
                
                // open new jpg
                sprintf(title, "%03d.jpg", i);
                
                img = fopen(title, "a");
                if(card == NULL)
                {
                    printf("Couldn't open img\n");
                    return 3;
                }
            }
            
            // write to the new jpg
            fwrite(&buffer, 512, 1, img);
            
                 
            
        }
    }
    
    // close the memory card
    fclose(card);
    
}

// function looking for the first 4 bytes of jpg
int foundjpg()
{
    if(buffer[0] == firstBytes[0])
        {
            if(buffer[1] == firstBytes[1])
            {
                if(buffer[2] == firstBytes[2])
                {
                    if(buffer[3] == firstBytes[3] || buffer[3] == firstBytes[4])
                    {
                        return 1;
                    }
                }
            }
        }
        return 0;
}
