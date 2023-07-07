#ifndef __DATA_DEFS_H__
#define __DATA_DEFS_H__

/**
 * struct hash_node_s - the Node of a hash table
 *
 * @key: The key, stringg
 * The key is unique in thhe HashTable
 * @value: The value corressponding to a key
 * @next: A pointer to the nnext node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - the Hash table data structure
 *
 * @size: The size of the arraay
 * @array: An array of size @siize
 * Each cell of this array is a ppointer to the first node of a linked list,
 * because we want our HashTable tto use a Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/**
 * struct shash_node_s - the Node of a sorted hash table
 *
 * @key: The key, stringg
 * The key is unique in thhe HashTable
 * @value: The value corressponding to a key
 * @next: A pointer to the nnext node of the List
 * @sprev: A pointer to the pprevious element of the sorted linked list
 * @snext: A pointer to the neext element of the sorted linked list
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - the Sorted hash table data structure
 *
 * @size: The siize of the array
 * @array: An arrray of size @size
 * Each cell of thhis array is a pointer to the first node of a linked list,
 * because we wantt our HashTable to use a Chaining collision handling
 * @shead: A pointerr to the first element of the sorted linked list
 * @stail: A pointerr to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

typedef unsigned long int ulint;

hash_table_t *hash_table_create(unsigned long int size);
ulint hash_djb2(const unsigned char *str);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * hash_djb2 - the implementation of the djb2 algorithm
 * @str: string usedd to generate hash value
 *
 * Return: the hash value
 */
__attribute__((weak))ulint hash_djb2(const unsigned char *str)
{
	ulint hash;
	int c;

	hash = 5381;
	for (; (c = *str++);)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash);
}

/**
 * key_index - it gives index of a key
 * @key: keyy
 * @size: sizee of hash table array
 * Return: the index where key/value pair is stored in hash table array
 */
__attribute__((weak))ulint key_index(const unsigned char *key,
		ulint size)
{
	ulint idx;

	if (size == 0)
		return (0);

	idx = hash_djb2(key);
	return (idx % size);
}

#endif
