#include "monty.h"
globa_v *gvar = NULL;

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: (0)
 */

int main(int ac, char **av)
{
	unsigned int line_number = 0;
	FILE *fd;
	char *buf = NULL;
	char **tokens = NULL;
	size_t size = 0;
       	ssize_t nb_read = 0;

	intialize_var();

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}


	while ((nb_read = getline(&buf, &size, fd)) != -1)
	{
		line_number++;
		tokens = parser(buf);
		interpret(tokens, line_number);
	}
	if (nb_read == -1)
		free(buf);

	fclose(fd);
	return (0);
}
