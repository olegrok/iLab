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
int list_find(struct list *l, value_t value);                //list search



/* For hash table*/
struct Table* table_ctor(int count, unsigned int (*function(char *str)))
                                                                //Create the table
void table_dtor(struct Table* table);                           //Delete the table
void fill_table(struct Table* table, FILE* file);               //Fills it from a file using the selected hash function
                                                                //Unloads the statistics file
void print_table(struct Table* table);                          //Prints the contents of the table
int table_remove_str(struct Table* table, char* str);           //Deletes a row from the table
int table_add(struct Table* table, char* str);                  //Add a row from the table
int table_search(struct Table* table, char* str);               //Search a row from the table


/* Auxiliary functions */
void print_hash_massive(struct list *l, int count);             //Prints the contents of the table cell
struct list* table_massive_ctor(int count);                     //Create hash table cells
