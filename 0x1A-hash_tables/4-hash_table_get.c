#include "hash_tables.h"

/**
 * hash_table_get - the given key, get value
 * @ht: hash tablee
 * @key: the key
 * Return: the value; or NULL if not found
 */
char *hash_table_get(const table_t *ht, const char *key)
{
	ulint idx;
	node_t *tmp;

	/* findd index in hash table where key is */
	/* lookk through linked list to find matching key for value */

	if (!ht || !key)
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);

	tmp = (ht->array)[idx];
	while (tmp != NULL && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	else
		return (tmp->value);
}
