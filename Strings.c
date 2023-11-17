#include "monty.h"

/**
 * op_pstr - prints strings from the top of the stack
 * @sp: is a pointer
 */
void op_pstr(stack_t **sp)
{
	stack_t *p = NULL;

	if (*sp)
	{
		(*sp)->next->prev = NULL;

		for (p = *sp; p && p->n > 0 && p->n < 128; p = p->prev)
			putchar(p->n);

		(*sp)->next->prev = *sp;
	}

	putchar('\n');
}


/**
 * tokcheck - Count the words in a string
 * @str: is the string to check
 *
 * Return: number of tokens in str.
 */
size_t tokcheck(const char *str)
{
	size_t sum = 0;

	while (*str)
	{
		while (isspace(*str))
			str++;
		if (!*str)
			break;
		do {
			str++;
		} while (*str && !isspace(*str));

		sum++;
	}
	return (sum);
}


/**
 * isinteger - check if a string is an integer
 * @str: the string to check
 *
 * Return: 1 if str represents an integer, otherwise 0
 */
int isinteger(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	if (!*str)
		return (0);

	while (isdigit(*str))
		str++;

	return (!*str);
}
