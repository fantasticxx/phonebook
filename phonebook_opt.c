#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "phonebook_opt.h"

hashTable *initHashTable(tableSize htsize)
{
    hashTable *ht = NULL;
    int i;
    if ((ht = (hashTable *) malloc(sizeof(hashTable))) == NULL)
        return NULL;


    if ((ht->hashEntry = (entry **) malloc(sizeof(entry*)*htsize)) == NULL)
        return NULL;


    for (i = 0; i < htsize; i++) {
        ht->hashEntry[i] = NULL;
    }

    ht->htsize = htsize;
    return ht;
}

size_t hash(char *lastName, hashTable *ht)
{
    size_t hash_val = 0;
    while (*lastName != '\0')
        hash_val += *lastName++;
    return hash_val % ht->htsize;
}

entry *findName(char lastName[], hashTable *ht)
{
    entry *tmp;
    size_t hashIndex = hash( lastName, ht);
    for (tmp = ht->hashEntry[hashIndex]; tmp != NULL; tmp = tmp->pNext) {
        if (strcmp(lastName, tmp->lastName) == 0) {
            return tmp;
        }
    }
    return NULL;
}

entry *append(char lastName[], hashTable *ht)
{
    size_t hashIndex = hash(lastName, ht);

    entry *newEntry;
    if ((newEntry = (entry *) malloc(sizeof(entry))) == NULL)
        return NULL;


    strcpy(newEntry->lastName, lastName);
    newEntry->pNext = ht->hashEntry[hashIndex];
    ht->hashEntry[hashIndex] = newEntry;
    return newEntry;
}


