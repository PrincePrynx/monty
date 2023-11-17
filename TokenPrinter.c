#include "monty.h"

/**
 * tokenize - function split a string into words
 * @str: the string to split
 *
 * Return: If memory allocation fails, or if str is NULL or contains no words,
 * return NULL. Else, return a NULL-terminated array of the words in str.
 */
char **tokenize(char *str)
{
	char **tokens = NULL;
	size_t sum = 0;

	if (!str)
		return (NULL);

	sum = tokcheck(str);
	if (!sum)
		return (NULL);

	tokens = malloc(sizeof(char *) * (1 + sum));
	if (!tokens)
		return (NULL);

	for (sum = 0; *str; ++sum)
	{
		while (isspace(*str))
			*str++ = '\0';
		if (*str)
			tokens[sum] = str;
		else
			break;
		do {
			++str;
		} while (*str && !isspace(*str));
	}
	tokens[sum] = NULL;

	return (tokens);
}
