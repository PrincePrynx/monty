#include "monty.h"

/**
 * free_op_env - function clears stack operation env
 *
 */

void free_op_env(void)
{
	free_stack(&op_env.sp);
	free(op_env.argv);
	free(op_env.line);
	op_env.argv = NULL;
	op_env.line = NULL;
}


/**
 * free_stack - free and nullify a stack
 * @sp: is a ptr
 */
void free_stack(stack_t **sp)
{
	stack_t *top = NULL;

	if (sp && *sp)
	{
		top = *sp;
		top->next->prev = NULL;
		do {
			*sp = top->prev;
			free(top);
		} while ((top = *sp));
	}
}
