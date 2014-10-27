#ifndef _GUARD
#define _GUARD
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct stack_t
    {
        int* data;
        int Count;
        int Max;
    };
    typedef struct stack_t* mystack;
int StackOK(const struct stack_t* stk)
    {
        if(stk && stk -> data && stk -> Count >= 0 && stk -> Count <= stk -> Max && stk -> Max > 0)
            return 1;
        else
            return 0;
    }
   void AsserStack(const struct stack_t* Stack, char name_function[])
    {
        if(!StackOK(Stack))
            {
                stack_dump(Stack);
                printf("Function: %s\n", name_function);
            }
        assert(StackOK(Stack));
    }
    int stack_dump(const struct stack_t* Stack)
    {
        int i = 0;
        printf("\n\n");
        printf("-------------------------------------------------\n");
        printf("Information about stack:\n");
        printf("Stack OK: ");
        if(StackOK(Stack))
             printf("true\n");
        else
            printf("false\n");
        printf("Count: %d\n", Stack -> Count);
        printf("Max: %d\n", Stack -> Max);
        printf("Adress: %d\n", *Stack);
        printf("Elements: \n");
        if(Stack -> Count < 0 || Stack -> Max < 0)
            printf("\t [0] No\n");
        if(Stack -> Count >= Stack -> Max)
        for(i = 0;i < Stack -> Max; i++)
        {
            printf("\t [%d] = %d", i, Stack -> data[i]);
            if(i <= Stack -> Count)
                printf("*\n");
            else
                printf("\n");
        }
        if(Stack -> Count == Stack -> Max)
            printf("Stack is FULL!\n");
        if(Stack -> Count < 0)
            printf("Invalid adress!\n");
        if(Stack -> Count == 0)
            printf("Stack is EMPTY\n");
        printf("-------------------------------------------------\n");
        printf("\n\n");
        return 1;
    }

struct stack_t* stack_construct(int stack_size)
    {
        struct stack_t *Stack = (struct stack_t*)calloc(1, sizeof(struct stack_t));
        Stack -> data = (int*)calloc(stack_size + 1, sizeof(int));
        Stack -> Max = stack_size;
        Stack -> Count = 0;
        AsserStack(Stack, (char*)__FUNCTION__);
        return Stack;
    }

int stack_destruct(struct stack_t* Stack)
    {
        int i = 0;
        for(i = 0; i < Stack -> Count; i++)
            {
               Stack -> data[i] = 0;
            }
        Stack -> Count = -1;
        Stack -> Max = -1;
        free(Stack -> data);
        free(Stack);
        Stack = 0;
        return 0;
    }
int stack_push(struct stack_t* Stack, int value)
    {
        AsserStack(Stack, (char*)__FUNCTION__);
        Stack -> data [Stack -> Count++] = value;
        AsserStack(Stack, (char*)__FUNCTION__);
    }
    int stack_top(struct stack_t* Stack)
    {
        if(Stack -> Count == 0)
            {
                printf("Stack is empty!\n");
                printf("Returned 0\n");
                return 0;
            }
        if(Stack -> Count < 0)
            {
                printf("Invalid stack\n");
                printf("Returned 0\n");
                return 0;
            }
        return Stack -> data[Stack -> Count];
    }
int stack_pop(struct stack_t* Stack)
    {
        AsserStack(Stack, (char*)__FUNCTION__);
        if(Stack -> Count == 0)
        {
            printf("Error! Stack is empty!\n");
                Stack -> Count--;
                AsserStack(Stack, (char*)__FUNCTION__);
        }
        return Stack -> data [Stack -> Count--];
    }
#endif
