#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: s- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *cppt;
	ssize_t jb;
	ssize_t s;
	ssize_t u;

	jb = open(filename, O_RDONLY);
	if (jb == -1)
		return (0);
	cppt = malloc(sizeof(char) * letters);
	u = read(jb, cppt, letters);
	s = write(STDOUT_FILENO, cppt, u);

	free(cppt);
	close(jb);
	return (s);
}




