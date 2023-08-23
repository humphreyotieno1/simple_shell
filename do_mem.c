#include "shell.h"

/**
 * do_mem - allocate memory and set all values to 0
 * @size: size of memory to allocate
 * @value: value to initialize memory
 * Return: pointer to allocated memory
 */

void *do_mem(size_t size, int value)
{
	void *ptr = malloc(size);

	if (ptr != NULL)
	{
		size_t i;

		for (i = 0; i < size; i++)
		{
		*((char *)ptr + i) = (char)value;
		}
	}
	return (ptr);
}
