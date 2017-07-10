/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>

#include "dictionary.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> 

int word_count = 0;


// pointer to the root of the trie    
node* root;
    
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    
    int i = 0, index = 0;
       
    node* path = root;
       
    while( word[i] != '\0')
    {
       if (isalpha(word[i]))
        {
            index = tolower(word[i]) - 'a';
        }
        else if(word[i] == '\'')
        {
            index = 26;
        }
        
            
       if(path->children[index] == NULL)
       {
           return false;
       }
       else
       {     
           path = path->children[index];
       }
       
       i++;
        
   }
   if(path->is_word == true)
   {
       return true;
   }
   else
   {
       return false;
   } 
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    
    int i = 0, index = 0;
    char word[LENGTH + 1];
    root = (node*)malloc(sizeof(node));
    node* path = root;
    
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        
        return false;
    }
    
    while(fscanf(fp, "%s", word) == 1)
    {
         while( word[i] != '\0')
         {
            if (isalpha(word[i]))
            {
                index = tolower(word[i]) - 'a';
            }
            else if(word[i] == '\'')
            {
                index = 26;
            }
            
            if(path->children[index] == NULL)
            {
                path->children[index] = (node*)malloc(sizeof(struct node));
            }
            
            path = path->children[index];
            i++;
        
        }
        word_count++;
        
        path->is_word = true;
        path = root;
        i = 0;
    
    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return word_count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    if(free_nodes(root) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * recursively free all nodes.Returns true if successful else false.
 */
bool free_nodes(node* node)
{
    for(int i = 0; i < 27; i++)
    {
        if(node->children[i] != NULL)
        {
            free_nodes(node->children[i]);
        }
    }
    free(node);
    
    return true;
}
