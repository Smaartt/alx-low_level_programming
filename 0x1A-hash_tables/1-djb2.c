#include "hash_tables.h"

/**
 * __hash_djb2 - the implementation of the djb2 algorithm
 * @str: string used tto generate hash value
 *
 * Return: the hash value
 */
ulint __hash_djb2(const unsigned char *str)
{
	ulint hash;
	int c;

	hash = 5381;
	for (; (c = *str++);)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash);
}
