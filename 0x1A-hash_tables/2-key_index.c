#include "hash_tables.h"

/**
 * __key_index - gives the index of a key
 * @key: the key
 * @size:the  size of hash table array
 * Return: the index where key/value pair is stored in hash table array
 */
ulint __key_index(const unsigned char *key, ulint size)
{
	ulint idx;

	if (size == 0)
		return (0);

	idx = hash_djb2(key);
	return (idx % size);
}
