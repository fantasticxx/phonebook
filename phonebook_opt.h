#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H
#define TABLE_SIZE 65599
#define MAX_LAST_NAME_SIZE 16
#define OPT
/* optimized version */
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pNext;
    struct info *Info;
} entry;

typedef struct __PHONE_BOOK_INFO {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} info;

typedef unsigned int tableSize;

typedef struct __HASH_TABLE {
    tableSize htsize;
    entry **hashEntry;
} hashTable;

hashTable *initHashTable(tableSize htsize);
size_t hash(char *lastName, hashTable *ht);
entry *findName(char lastName[],hashTable *ht);
entry *append(char lastName[], hashTable *ht);

#endif
