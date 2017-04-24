/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define LOWERCASE_A 97
#define APOSTROPHE 26

#include "dictionary.h"

typedef struct _trie
{
    bool isWord;
    struct _trie *children[27];
} node ;

// Declare root node
node *root = malloc(sizeof(node));
int dicWordCount = 0;

/**
 * Returns the index of a letter in a node
 */
int getindex(const char ch)
{
    if(ch == '\'')
        return APOSTROPHE;
    else
        return tolower(ch) - LOWERCASE_A ;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE *inptr = fopen(dictionary,"r");
    char word[45];
    int i, index;
    node *newNode = root;
    while(feof(inptr) == 0)
    {
        fscanf(inptr, "%s", word);
        for(i = 0; word[i] != '\0', i++)
        {
            index = getindex(word[i]);
            if(newNode->children[index] == NULL)
            {
                newNode->children[index] = malloc(sizeof(node));
            
                if(newNode->children[index] == NULL)
                {
                    return false;
                }
            }
            newNode = newNode->children[index];
        }
        newNode->isWord = true;
        dicWordCount++;
    }
    if (ferror(inptr))
    {
        fclose(inptr);
        unload();
        return false;
    }
    fclose(inptr);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dicWordCount;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    unload(root);
}
