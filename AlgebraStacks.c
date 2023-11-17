#include "monty.h"

/**
 * op_add - adds the top two elements on the stack
 * @sp: stack pointer
 */
void op_add(stack_t **sp)
{
	int plus = 0;

	if (!(*sp && *sp != (*sp)->next))
		errors("L%u: can't add, stack too short\n", op_env.lineno);

	plus = (*sp)->n;

	op_pop(sp);

	(*sp)->n += plus;
}


/**
 * op_div - divides the top two elements on the stack
 * @sp: ...
 */
void op_div(stack_t **sp)
{
	int divs = 0;

	if (!(*sp && *sp != (*sp)->next))
		errors("L%u: can't div, stack too short\n", op_env.lineno);

	divs = (*sp)->n;
	if (!divs)
		errors("L%u: division by zero\n", op_env.lineno);

	op_pop(sp);

	(*sp)->n /= divs;
}


/**
 * op_mod - mod the top two elements on the stack
 * @sp: ...
 */
void op_mod(stack_t **sp)
{
	int modi = 0;

	if (!(*sp && *sp != (*sp)->next))
		errors("L%u: can't mod, stack too short\n", op_env.lineno);

	modi = (*sp)->n;
	if (!modi)
		errors("L%u: division by zero\n", op_env.lineno);

	op_pop(sp);

	(*sp)->n %= modi;
}


/**
 * op_mul - multiplies the top two elements on the stack
 * @sp: is a ptr
 */
void op_mul(stack_t **sp)
{
	int mulx = 0;

	if (!(*sp && *sp != (*sp)->next))
		errors("L%u: can't mul, stack too short\n", op_env.lineno);

	mulx = (*sp)->n;

	op_pop(sp);

	(*sp)->n *= mulx;
}
