#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
struct stack_t
    {
        int* data;
        struct stack_t* pre;
        int Count;
        int Max;
    };
int StackOK(const stack_t* stk)
    {
        if((stk && stk -> data && stk -> Count >= 0 && stk -> Count <= stk -> Max) != 0)
            return 1;
        else
            return 0;
    }
    void AsserStack(stack_t* Stack)
    {
        assert(StackOK(Stack));
    }

stack_t* stack_construct(int stack_size)
    {
        stack_t *Stack = (stack_t*)calloc(1, sizeof(stack_t));
        Stack -> data = (int*)calloc(stack_size, sizeof(int));
        Stack -> Max = stack_size;
        Stack -> Count = 0;
        Stack -> pre = (stack_t*)calloc(stack_size, sizeof(stack_t));
        Stack -> pre = NULL;
        AsserStack(Stack);
        return Stack;
    }
int destruct_stack(stack_t* Stack)
    {
        int i = 0;
        for(i = 0; i < Stack -> Count; i++)
            {
               Stack -> data[i] = 0;
               Stack -> pre = NULL;
            }
        Stack -> Count = -1;
        free(Stack -> data);
        free(Stack -> pre);
        free(Stack);
        return 0;
    }
int stack_push(stack_t* Stack, int value)
    {
        AsserStack(Stack);
        Stack -> Count++;
        Stack -> data [Stack -> Count] = value;
        Stack -> pre = Stack;
        AsserStack(Stack);
        if(Stack -> Count == Stack -> Max)
            printf("WARNING! Stack is FULL!\n");
    }
int stack_pop(stack_t* Stack)
    {
        AsserStack(Stack);
        int buf = 0;
        buf = Stack -> data [Stack -> Count];
        Stack -> Count--;
        AsserStack(Stack);
        return buf;
    }

int main()

{
    const int c = 3;
    int varible = 0, i = 0;
    stack_t* NEW = stack_construct(c);
    printf("%d\n", NEW -> Max);

    for(i = 0; i < c; i++)
        {
            scanf("%d", &varible);
            stack_push(NEW, varible);
        }

    for(i = 0; i < c; i++)
        {
            printf("%d\n", stack_pop(NEW));
        }
    printf("%d",StackOK(NEW));
    destruct_stack(NEW);
    //assert(StackOK(NEW));
    printf("%d",StackOK(NEW));
    return 0;
}
