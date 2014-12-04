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


void list_dump(struct list *l, int count)
{
    assert(l);
    int i = 0;
    for(i = 0; i < count; i++)
        assert(&l[i]);

}
struct list* new_list(int count) //list constructor
{
   int i = 0;
   struct list *res = (struct list*) calloc(count, sizeof(struct list));
   for(;i < count; i++)
   {

        res[i].first = NULL;
        res[i].size = 0;
   }
   list_dump(res, count);
   return res;
}

struct li* new_list_item(key_t key, value_t value) //list's element constructor
{
    struct li *res = (struct li*) calloc(1, sizeof(struct li));
    res -> key = key;
    res -> value = (char*)calloc(strlen(value) + 1, sizeof(char));
    strcpy(res -> value, value);
    res -> next = NULL;
    assert(res);
    return res;
}
void delete_items(struct li* it) //list element destructor
{
    if(it)
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
    assert(l);
    if (l)
    {
        delete_items(l -> first);
    }
}

void delete_hash_table(struct list *l, int count) //table destructor
{
    int i = 0;
    for(i = 0; i < count; i++)
        delete_one_list(&l[i]);
    free(l);
}


int insert_item(struct list *l, key_t key, value_t value) //add element
{
    assert(l);
    struct li *it = new_list_item(key,value);
    assert(it);
    it -> next = l -> first;
    l -> first = it;
    l -> size++;
    assert(l);
    assert(it);
    return 1;
}

void print_list (struct list *l) //List print
{
    assert(l);
    struct li *it = l -> first;
    printf( "Size = %d     ", l -> size );
    for (; it;  )
        {
            printf("(%d,%s)  ->  ", it -> key, it -> value);
            it = it -> next;
        }
   printf( "NULL\n" );
}

int list_find(struct list *l, value_t value) //list search
{
    assert(l);
    struct li *it;
    for ( it = l -> first; it != NULL; it = it -> next )
    {
        if (!strcmp(it -> value, value))
            return 1;
        {
        }
    }
    return 0;
}
