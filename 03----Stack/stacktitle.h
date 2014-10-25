#include "stacklib.h"
#include "assembler.h"
struct stack_t* stack_construct(int stack_size);
int stack_destruct(struct stack_t* Stack);
int stack_push(struct stack_t* Stack, int value);
int stack_top(struct stack_t* Stack);
int stack_pop(struct stack_t* Stack);
int assembler();
void disassembler();
int stack_dump(const struct stack_t* Stack);
