#include "monty.h"

/**
 * main - The main function in the monty interpreter
 *
 * @argc: The number of arguments passed in
 * @argv: An array of all passed in arguments
 *
 * Return: int: iono particularly which ones
 */

int main(int argc, char **argv)
{
	char **cmd_array;
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	cmd_array = malloc(200 * sizeof(char *));
	if (cmd_array == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < 200; i++)
	{
		cmd_array[i] = malloc(100 * sizeof(char));
		if (cmd_array[i] == NULL)
		{
			for (; i >= 0; i--)
				free(cmd_array[i]);
			free(cmd_array);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
	}
	readfile(argv[1], cmd_array, "\n");
	run_opcodes(cmd_array);
	/*printf("%s\n", cmd_array[0]);*/
	for (i = 0; i < 200; i++)
		free(cmd_array[i]);
	free(cmd_array);
	return (0);
}
