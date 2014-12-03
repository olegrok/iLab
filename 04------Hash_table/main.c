#include "header.h"
int main()
{
    const int count = 119;
    FILE* file;
    file = fopen("Book.txt","r+");
    fill_table(file, count, HashRot13);
    fill_table(file, count, HashFAQ6);
    fill_table(file, count, HashLy);
    fill_table(file, count, HashRs);
    fclose(file);
    return 0;
}
