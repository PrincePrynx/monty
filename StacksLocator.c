#include "monty.h"

/**
 * op_pall - prints each element on the stack
 * @sp: stack pointer
 */
void op_pall(stack_t **sp)
{
	stack_t *p = NULL;

	if (*sp)
	{
		(*sp)->next->prev = NULL;

		for (p = *sp; p; p = p->prev)
			printf("%d\n", p->n);

		(*sp)->next->prev = *sp;
	}
}


/**
 * op_pint - prints the value at the top of the stack
 * @sp: ...
 */
void op_pint(stack_t **sp)
{
	if (*sp)
		printf("%d\n", (*sp)->n);
	else
		errors("L%u: can't pint, stack empty\n", op_env.lineno);
}

/**
 * op_pop - deletes element at the top of the stack
 * @sp: ...
 */
void op_pop(stack_t **sp)
{
	stack_t *top = NULL;

	if (!*sp)
		errors("L%u: can't pop an empty stack\n", op_env.lineno);

	if (*sp != (*sp)->prev)
	{
		top = (*sp)->prev;
		(*sp)->next->prev = top;
		top->next = (*sp)->next;
	}
	free(*sp);
	*sp = top;
}


/**
 * op_pchar - prints char at the top of the stack
 * @sp: ...
 */
void op_pchar(stack_t **sp)
{
	if (*sp)
	{
		if ((*sp)->n > 0 && (*sp)->n < 128)
			printf("%c\n", (*sp)->n);
		else
			errors("L%u: can't pchar, value out of range\n", op_env.lineno);
	}
	else
		errors("L%u: can't pchar, stack empty\n", op_env.lineno);


}
