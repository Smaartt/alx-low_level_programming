#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a given file.
 * @filename: A pointer that points to the name of the file.
 * @text_content: The string to be added to the end of the file.
 *
 * Return: If the function fails or filename is NULL, return - -1.
 * If the file does not exist the user lacks write permissions, return - -1.
 *         Otherwise, return - 1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int p, q, lent = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lent = 0; text_content[lent];)
			lent++;
	}

	p = open(filename, O_WRONLY | O_APPEND);
	q = write(p, text_content, lent);

	if (p == -1 || q == -1)
		return (-1);

	close(p);

	return (1);
}





