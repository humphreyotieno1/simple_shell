#include "shell.h"

/**
 * free_double_array - free memory allocated for a double char ptr
 * @array: double char ptr to be freed
 */

void free_double_array(char **array)
{
	int i;

	if (array == NULL)
	{
		return;
	}

	for (i = 0; array[i] != NULL; i++)
		free(array[i]);
	free(array);
}
