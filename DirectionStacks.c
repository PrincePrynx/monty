#include "monty.h"

/**
 * op_rotl - rotates toward top of stack
 * @sp: stack pointer
 */
void op_rotl(stack_t **sp)
{
	if (*sp)
		*sp = (*sp)->prev;
}


/**
 * op_rotr - rotates toward bottom of stack
 * @sp: ...
 */
void op_rotr(stack_t **sp)
{
	if (*sp)
		*sp = (*sp)->next;
}
