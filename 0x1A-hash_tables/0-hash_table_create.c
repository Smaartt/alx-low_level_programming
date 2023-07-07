#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the hash table to createe
 * Return: pointer to the newly created tablle
 */
hash_table_t *hash_table_create(ulint size)
{
	table_t *ht;
	node_t **array;
	ulint i;

	ht = malloc(sizeof(table_t));
	if (!ht)
		return (NULL);

	array = malloc(sizeof(*array) * size);
	if (!array)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		array[i] = NULL;

	ht->size = size;
	ht->array = array;

	return (ht);
}
