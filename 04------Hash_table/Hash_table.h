#define _NOT_FOUND_ -1
struct Table
{
    int count;
    unsigned int(*Funct)(char* str);
    struct list* hash_table;
};
struct list* table_massive_ctor(int count)
{
    struct list* hash_table = new_list(count);
    return hash_table;
}
void massive_table_dtor(struct list* hash_table, int count)
{
    delete_hash_table(hash_table, count);
}
struct Table* table_ctor(int count, unsigned int (*function(char *str)))
{
    struct Table * ht = calloc(1, sizeof(struct Table));
    ht -> count = count;
    ht -> Funct = function;
    ht -> hash_table = table_massive_ctor(count);
    return ht;

}
void table_dtor(struct Table* table)
{
    struct list* hash_table = table -> hash_table;
    int count = table -> count;
    massive_table_dtor(hash_table, count);
    free(table);

}
int table_search(struct Table* table, char* str)
{
    assert(table);
    struct list* hash_table = table -> hash_table;
    int count = table -> count;
    unsigned int hash = 0;
    hash = abs(table -> Funct(str));
    if(!list_find(&hash_table[hash % count], str))
    {
        return _NOT_FOUND_;
    }
    return hash;
}
int table_add(struct Table* table, char* str)
{
    assert(table);
    struct list* hash_table = table -> hash_table;
    int count = table -> count;
    unsigned int hash = 0;
    hash = abs(table -> Funct(str));
    if(list_find(&hash_table[hash % count], str))
        return 0;
    insert_item(&hash_table[hash % count], hash, str);
    assert(table);
    return 1;
}
void print_hash_massive(struct list *l, int count)
{
    assert(l);
    int i = 0;
    for(i = 0; i < count; i++)
    {
        printf("List No. %d\n", i);
        print_list(&l[i]);
    }
}
void print_table(struct Table* table)
{
    struct list* hash_table = table -> hash_table;
    int count = table -> count;
    print_hash_massive(hash_table, count);
    table = NULL;

}
int table_remove_str(struct Table* table, char* str)
{
    assert(table);
    struct list* hash_table = table -> hash_table;
    int count = table -> count;
    assert(hash_table);
    unsigned int hash = 0;
    hash = abs(table -> Funct(str));
    struct list* l = &hash_table[hash % count];
    struct li *it = NULL;
    struct li *buf = NULL;
    struct li *prev = l -> first;
    if(list_find(l, str))
    {
       for (it = l -> first; it != NULL; it = it -> next)
        {
            if (!strcmp(it -> value, str))
            {
                strcpy(it -> value, "");
                it -> key = 0;
                l -> size--;
                return 1;
            }
        }
        assert(table);
    }
    assert(table);
    return _NOT_FOUND_;
}
void fill_table(struct Table* table, FILE* file)
{
    unsigned int hash = 0, i = 0;
    struct list* hash_table = table -> hash_table;
    int count = table -> count;
    FILE* results;
    results = fopen("Res.csv", "a");
    if(file == NULL)
    {
        for(i = 0; i < count; i++)
            fprintf(results, "%d, ", hash_table[i].size);
        return;
    }
    rewind(file);
    char* str = (char*)calloc(90, sizeof(char));
    while(!feof(file))
    {
        fscanf(file, "%s", str);
        hash = abs(table -> Funct(str));
        if(!list_find(&hash_table[hash % count], str))
            {
                insert_item(&hash_table[hash % count], hash, str);
            }
    }
    free(str);
    for(i = 0; i < count; i++)
        fprintf(results, "%d, ", hash_table[i].size);
    fprintf(results, "%s", "\n");
    fclose(results);

}
