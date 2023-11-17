#include "monty.h"

/**
 * op_stack - set stack mode to last-in first-out (default)
 * @sp: stack pointer
 */
void op_stack(stack_t **sp __attribute__((unused)))
{
	op_env.mode = LIFO;
}

/**
 * op_sub - sub the top two elements on the stack
 * @sp: stack pointer
 */
void op_sub(stack_t **sp)
{
	int subs = 0;

	if (!(*sp && *sp != (*sp)->next))
		errors("L%u: can't sub, stack too short\n", op_env.lineno);

	subs = (*sp)->n;

	op_pop(sp);

	(*sp)->n -= subs;
}


/**
 * op_swap - Swap the top two elements on the stack
 * @sp: ...
 */
void op_swap(stack_t **sp)
{
	stack_t *p = *sp;

	if (!(p && p != p->next))
		errors("L%u: can't swap, stack too short\n", op_env.lineno);

	p->n ^= p->prev->n;
	p->prev->n ^= p->n;
	p->n ^= p->prev->n;
}


/**
 * op_push - push an element onto the stack
 * @sp: ...
 */
void op_push(stack_t **sp)
{
	stack_t *new = NULL;
	const char *nstr = op_env.argv[1];

	if (!(nstr && isinteger(nstr)))
		errors("L%u: usage: push integer\n", op_env.lineno);

	new = malloc(sizeof(*new));
	if (!new)
		errors("Error: malloc failed\n");

	new->n = atoi(nstr);
	if (*sp)
	{
		new->prev = (*sp);
		new->next = (*sp)->next;
		new->next->prev = new;
		(*sp)->next = new;
		if (op_env.mode == LIFO)
			(*sp) = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
		(*sp) = new;
	}
}


/**
 * op_queue - set stack mode to first-in first-out
 * @sp: ...
 */
void op_queue(stack_t **sp __attribute__((unused)))
{
	op_env.mode = FIFO;
}
