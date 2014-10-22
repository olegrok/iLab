#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
struct stack_t
    {
        int* data;
        int Count;
        int Max;
    };
int StackOK(const struct stack_t* stk)
    {
        if((stk && stk -> data && stk -> Count >= 0 && stk -> Count <= stk -> Max) != 0)
            return 1;
        else
            return 0;
    }


struct stack_t* stack_construct(int stack_size)
    {
        struct stack_t *Stack = (struct stack_t*)calloc(1, sizeof(struct stack_t));
        Stack -> data = (int*)calloc(stack_size, sizeof(int));
        Stack -> Max = stack_size;
        Stack -> Count = 0;
        AsserStack(Stack, __FUNCTION__);
        return Stack;
    }
int destruct_stack(struct stack_t* Stack)
    {
        int i = 0;
        for(i = 0; i < Stack -> Count; i++)
            {
               Stack -> data[i] = 0;
            }
        Stack -> Count = -1;
        free(Stack -> data);
        free(Stack);
        return 0;
    }
int stack_push(struct stack_t* Stack, int value)
    {
        AsserStack(Stack, __FUNCTION__);
        Stack -> Count++;
        Stack -> data [Stack -> Count - 1] = value;
        //Stack -> pre = Stack;
        AsserStack(Stack, __FUNCTION__);
        if(Stack -> Count == Stack -> Max)
            printf("WARNING! Stack is FULL!\n");
    }
    int stack_top(struct stack_t* Stack)
    {
        return Stack -> data[Stack -> Count - 1];
    }
int stack_pop(struct stack_t* Stack)
    {
        AsserStack(Stack, __FUNCTION__);
        int buf = 0;
        buf = Stack -> data [Stack -> Count - 1];
        Stack -> Count--;
        //Stack -> pre = Stack;
        AsserStack(Stack, __FUNCTION__);
        return buf;
    }
    void stack_dump(const struct stack_t* Stack)
    {
        int i = 0;
        printf("Information about stack:\n");
        printf("Count: %d\n", Stack -> Count);
        printf("Max: %d\n", Stack -> Max);
        printf("Adress: %d\n", Stack);
        printf("Elements: \n");
        for(i = 0;i < Stack -> Max; i++)
        {
            printf("\t [%d] = %d", i, Stack -> data[i]);
            if(i < Stack -> Count)
                printf("*\n");
            else
                printf("\n");
        }
        if(Stack -> Count >= Stack -> Max)
            printf("Stack is FULL!\n");
        if(Stack -> Count < 0)
            printf("Invalid adress!\n");
        if(Stack -> Count == 0)
            printf("Stack is EMPTY\n");

    }
    void AsserStack(const struct stack_t* Stack, char* name_function)
    {
        if(!StackOK(Stack))
            {
                stack_dump(Stack);
                printf("Function: %s\n", name_function);
            }
        assert(StackOK(Stack));
    }

int main()

{
    const int c = 4;
    int varible = 0, i = 0;
    struct stack_t* NEW = stack_construct(c);
    printf("%d\n", NEW -> Max);

    for(i = 0; i < c + 1; i++)
        {
            scanf("%d", &varible);
            stack_push(NEW, varible);
        }
    stack_dump(NEW);
    //printf("%d\n", stack_top(NEW));
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
