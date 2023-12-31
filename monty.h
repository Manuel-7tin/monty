#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

void pop(unsigned int line_number);
void swap(unsigned int line_number);
void add(unsigned int line_number);
void nop(unsigned int line_number);
void sub(unsigned int line_number);
void mul(unsigned int line_number);
void mod(unsigned int line_number);
void pchar(unsigned int line_number);
void pstr(unsigned int line_number);
int readfile(char *filename, char **str_array, char *delimiter);
void push_stack(char *cmd, int line_number);
void pall_stack(void);
int run_opcodes(char **cmds);
void free_stack(void);
void pint_stack(int line_number);
void divde(unsigned int line_number);

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stack;

#endif /*HEADER_H*/
