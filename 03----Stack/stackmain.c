#include "stacktitle.h"
int main()

{
    const int c = 5;
    int varible = 0, i = 0;
    struct stack_t* NEW = stack_construct(c);
    stack_dump(NEW);
    printf("%d\n", NEW -> data[0]);
    printf("%d\n",StackOK(NEW));

    for(i = 0; i < c; i++)
        {
            scanf("%d", &varible);
            stack_push(NEW, varible);
        }
    stack_dump(NEW);
    printf("%d\n", stack_top(NEW));
    for(i = 0; i < c; i++)
        {
            printf("%d\n", stack_pop(NEW));
        }
    printf("%d\n",StackOK(NEW));
    destruct_stack(NEW);
    printf("%d\n",StackOK(NEW));
    stack_dump(NEW);
    return 0;
}
