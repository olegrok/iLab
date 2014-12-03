void fill_table(FILE* file, int count, unsigned int (*function(char *str)))
{
    unsigned int hash = 0, i = 0;
    struct list* hash_table = new_list(count);
    FILE* results;
    rewind(file);
    char* str = (char*)calloc(90, sizeof(char));
    results = fopen("Res.csv", "a");
    while(!feof(file))
    {
        fscanf(file, "%s", str);
        punct(str);
        hash = abs(function(str));
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
    delete_hash_table(hash_table, count);

}
