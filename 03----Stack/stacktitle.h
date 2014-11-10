#include "stacklib.h"
#include "assembler.h"
typedef struct stack_t* mystack;


mystack stack_construct(int stack_size);
int stack_destruct(struct stack_t* Stack);
int stack_push(struct stack_t* Stack, int value);
int stack_top(struct stack_t* Stack);
int stack_pop(struct stack_t* Stack);
int assembler();
int disassembler();
int stack_dump(const struct stack_t* Stack);

