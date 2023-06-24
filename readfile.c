#include "monty.h"

/**
 * readfile - Reads all chars in a file and splits them using a delimiter
 *
 * @filename: The file to read from
 * @str_array: Array to store the chars
 * @delimiter: The delimiter
 *
 * Return: 0 on success
 */

int readfile(char *filename, char **str_array, char *delimiter)
{
	int fd, i;
	char *line = NULL, *buf = malloc(2000 * sizeof(char));

	if (buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!filename || !str_array || !delimiter)
	{
		free(buf);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free(buf);
		exit(EXIT_FAILURE);
	}
	read(fd, buf, 2000 * sizeof(char));
	line = strtok(buf, delimiter);
	for (i = 0; line; i++)
	{
		strcpy(str_array[i], line);
		line = strtok(NULL, delimiter);
	}
	strcpy(str_array[i], "NULL");
	free(buf);
	close(fd);
	return (0);
}
