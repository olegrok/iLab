#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
typedef int key_t;
typedef char* value_t;

struct li
{
   key_t key;
   value_t value;
   struct li* next;
};

struct list
{
   struct li *first;
   int size;
};




struct list* new_list(int count) //list constructor
{
   int i = 0;
   struct list *res = (struct list*) calloc(count, sizeof(struct list));
   for(;i < count; i++)
   {

        res[i].first = NULL;
        res[i].size = 0;
   }
   return res;
}

struct li* new_list_item(key_t key, value_t value) //list's element constructor
{
    struct li *res = (struct li*) calloc(1, sizeof(struct li));
    res -> key = key;
    res -> value = (char*)calloc(strlen(value) + 1, sizeof(char));
    strcpy(res -> value, value);
    res -> next = NULL;
    return res;
}

void delete_items(struct li* it) //list element destructor
{

   if (it)
    {
      if (it -> next)
      {
         delete_items(it -> next);
      }

      free(it -> value);
      free(it);
   }
}

void delete_one_list(struct list *l) //list destructor
{
   if (l)
    {
      delete_items(l -> first);
    }
}

void delete_hash_table(struct list *l, int count)
{
    int i = 0;
    for(i = 0; i < count; i++)
        delete_one_list(&l[i]);
    free(l);
}


int insert_item(struct list *l, key_t key, value_t value ) //add element
{
   struct li *it = new_list_item(key,value);
   assert(it);
   it -> next = l -> first;
   l -> first = it;
   l -> size++;
   return 1;
}

void print_list ( struct list *l) //List print
{
   struct li *it = l -> first;
   printf( "Size = %d     ", l -> size );
   for (; it;  )
    {
      printf("(%d,%s)  ->  ", it -> key, it -> value);
      it = it -> next;
    }
   printf( "NULL\n" );
}
void print_table(struct list *l, int count)
{
    int i = 0;
    for(i = 0; i < count; i++)
    {
        printf("List №%d\n", i);
        print_list(&l[i]);
    }
}
int list_find(struct list *l, value_t value) //list search
{
   struct li *it;
   for ( it = l -> first; it != NULL; it = it->next )
   {
      if (!strcmp(it -> value, value) )
      {
         return 1;
      }
   }
   return 0;
}
































unsigned int Hash_f(const char * str)
{

    unsigned int hash = 0;

    for (; *str; str++)
    {
        hash += (unsigned char)(*str);
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;

}

void punct(char* str)
{
    int last_symb = strlen(str) - 1;
    if(iswpunct(str[last_symb]))
        str[last_symb] = 0;

}



int main()
{
   const int count = 119;
   unsigned int hash = 0;
   int hash_residue = 0, i = 0;
   struct list* hash_table = new_list(count);
   FILE* file;
   FILE* results;
   char* str = (char*)calloc(90, sizeof(char));
   file = fopen("bk.txt","r+");
   results = fopen("Res.csv", "w+");

   while(!feof(file))
   {
        fscanf(file, "%s", str);
        //printf("%s\n", str);
        punct(str);
        hash = abs(Hash_f(str));
        if(!list_find(&hash_table[hash % count], str))
            {


                insert_item(&hash_table[hash % count], hash, str);


            }


   }
    fclose(file);
    for(i = 0; i < count; i++)
        fprintf(results, "%d, ", hash_table[i].size);
   //print_table(hash_table, count);



    delete_hash_table(hash_table, count);


    fclose(results);
    free(str);





   return 0;
}
