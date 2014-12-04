#include "header.h"

int main()
{
    const int count = 119;
    FILE* file;
    struct Table* table = table_ctor(count, HashRot13);

    file = fopen("Book.txt","r+");
    fill_table(table, file);
    print_table(table);
    table_dtor(table);

    fclose(file);
    return 0;

}
