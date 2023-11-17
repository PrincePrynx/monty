#include "monty.h"

/**
 * op_nop - function does nothing
 * @sp: is a pointer
 */
void op_nop(stack_t **sp __attribute__((unused)))
{}


/**
 * errors - function prints an error message and exit
 * @fmt: is the format str
 * @...: shows the format string parameters
 *
 * Description: Prints a message on stderr and exit with status EXIT_FAILURE.
 */
void errors(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);

	vfprintf(stderr, fmt, args);

	va_end(args);

	exit(EXIT_FAILURE);
}
