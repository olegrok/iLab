#ifndef _GUARD
#define _GUARD
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
const int OK = 1;
const int Error = 0;
const double Error_for_int_function = 0.5;

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
            return OK;
        else
            return Error;
    }

   void AssertStack(const struct stack_t* Stack, char name_function[])
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
        printf("Adress: %d\n", Stack);
        printf("Elements: \n");
        if(Stack -> Count < 0 || Stack -> Max < 0)
            printf("\t [0] No\n");
        if(Stack -> Count <= Stack -> Max)
        for(i = 0;i < Stack -> Max; i++)
        {
            printf("\t [%d] = %d", i, Stack -> data[i]);

            if(i < Stack -> Count)
                printf("*\n");
            else
                printf("\n");

        }
        if(Stack -> Count == Stack -> Max && Stack -> Max > 0 && Stack -> Count >= 0)
            printf("Stack is FULL!\n");
        if(Stack && Stack -> data && Stack -> Count < 0)
            printf("Invalid adress!\n");
        if(Stack -> Count == 0)
            printf("Stack is EMPTY\n");
        printf("-------------------------------------------------\n");
        printf("\n\n");
        return OK;
    }

struct stack_t* stack_construct(int stack_size)
    {
        struct stack_t *Stack = (struct stack_t*)calloc(1, sizeof(struct stack_t));
        Stack -> data = (int*)calloc(stack_size + 1, sizeof(int));
        Stack -> Max = stack_size;
        Stack -> Count = 0;
        AssertStack(Stack, (char*)__FUNCTION__);
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
        Stack = NULL;
        return OK;
    }
int stack_push(struct stack_t* Stack, int value)
    {
        AssertStack(Stack, (char*)__FUNCTION__);
        if(Stack -> Count == Stack -> Max)
            {
                Stack -> Max++;
                Stack = (struct stack_t*)realloc(Stack, Stack -> Max + 1);
                AssertStack(Stack, (char*)__FUNCTION__);
            }

        Stack -> data [Stack -> Count] = value;
        Stack -> Count++;
        AssertStack(Stack, (char*)__FUNCTION__);
        return OK;
    }
    int stack_top(struct stack_t* Stack)
    {
        AssertStack(Stack,(char*)__FUNCTION__);
        int buf = 0;
        if(Stack -> Count == 0)
            {
                printf("Stack is empty!\n");
                printf("Returned 0.5\n");
                return Error_for_int_function;
            }
        if(Stack -> Count < 0)
            {
                printf("Invalid stack\n");
                printf("Returned 0.5\n");
                return Error_for_int_function;
            }
        Stack -> Count--;
        buf = Stack -> data[Stack -> Count];
        Stack -> Count++;
        return buf;
    }
int stack_pop(struct stack_t* Stack)
    {
        AssertStack(Stack, (char*)__FUNCTION__);
        int buf = 0;
        if(Stack -> Count == 0)
            {
                printf("Error! Stack is empty!\n");
                    return Error_for_int_function;
            }
        Stack -> Count--;
        buf = Stack -> data [Stack -> Count];
        Stack -> data [Stack -> Count] = 0;
        AssertStack(Stack, (char*)__FUNCTION__);
        return buf;
    }
#endif
