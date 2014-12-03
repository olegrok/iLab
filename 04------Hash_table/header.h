#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "Hash_functions.h"
#include "List.h"
#include "Hash_table.h"
/* Hash functions */
unsigned int HashFAQ6(const char * str);
unsigned int HashRot13(const char * str);
unsigned int HashLy(const char * str);
unsigned int HashRs(const char * str);


/* For list */
void list_dump(struct list *l, int count);                   //dump
struct list* new_list(int count);                            //list constructor
struct li* new_list_item(key_t key, value_t value);          //list's element constructor
void delete_items(struct li* it);                            //list element destructor
void delete_one_list(struct list *l);                        //list destructor
void delete_hash_table(struct list *l, int count);           //table destructor
int insert_item(struct list *l, key_t key, value_t value);   //add element
void print_list (struct list *l);                            //list print
void print_table(struct list *l, int count);                 //table print
int list_find(struct list *l, value_t value);                //list search
void punct(char* str);                                       //removes the last character in a word, if it is a punctuation mark


/* For hash table*/
void fill_table(FILE* file, int count, unsigned int (*function(char *str)));
/*
Creates a hash table
Fills it from a file using the selected hash function
Unloads the statistics file
Remove table
*/
