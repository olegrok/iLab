#include "stacklib.h"
#include "assembler.h"
struct stack_t* stack_construct(int stack_size);
int destruct_stack(struct stack_t* Stack);
int stack_push(struct stack_t* Stack, int value);
int stack_top(struct stack_t* Stack);
int stack_pop(struct stack_t* Stack);
void stack_dump(const struct stack_t* Stack);
void assembler();
void disassembler();
