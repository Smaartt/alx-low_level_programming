#include "main.h"

/**
 * create_file - Creates a new file.
 * @filename: A pointer that points to the name of the file to create.
 * @text_content: A pointer that points to a string to write to the file.
 *
 * Return: If the function fails, return - -1.
 *         Otherwise return - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int jb, s, lent = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lent = 0; text_content[lent];)
			lent++;
	}

	jb = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	s = write(jb, text_content, lent);

	if (jb == -1 || s == -1)
		return (-1);

	close(jb);

	return (1);
}

