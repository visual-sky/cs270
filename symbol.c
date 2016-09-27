#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "symbol.h"

/** @file symbol.c
 *  @brief You will modify this file and implement the symbol.h interface
 *  @details Your implementation of the functions defined in symbol.h.
 *  You may add other functions if you find it helpful. Added functions
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 * <p>
 * @author <b>Your name</b> goes here
 */

/** size of LC3 memory */
#define LC3_MEMORY_SIZE  (1 << 16)

/** Provide prototype for strdup() */
char *strdup(const char *s);

/** defines data structure used to store nodes in hash table */
typedef struct node {
  struct node* next;     /**< linked list of symbols at same index */
  int          hash;     /**< hash value - makes searching faster  */
  symbol_t     symbol;   /**< the data the user is interested in   */
} node_t;

/** defines the data structure for the hash table */
struct sym_table {
  int      size;        /**< size of hash table         */
  node_t** hash_table;  /**< array of linked list heads */
  char**   addr_table;  /**< look up symbols by addr    */
};

/** djb hash - found at http://www.cse.yorku.ca/~oz/hash.html
 * tolower() call to make case insensitive.
 */

static int symbol_hash (const char* name) {
  unsigned char* str  = (unsigned char*) name;
  unsigned long  hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */

  c = hash & 0x7FFFFFFF; /* keep 31 bits - avoid negative values */

  return c;
}

/** @todo implement this function */
sym_table_t* symbol_init (int table_size) {
  node_t* hash_tab[table_size];
  char* addr_tab = calloc(LC3_MEMORY_SIZE, sizeof(char));
  for (int i=0;i<table_size;i++) {
    node_t null_node;
    null_node.next = NULL;
    hash_tab[i] = &null_node;
  }
  for (int i=0;i<LC3_MEMORY_SIZE;i++) {
    char ch = NULL;
    addr_tab[i] = &ch;
  }
  sym_table_t *sym_tab = calloc(1, sizeof(sym_table_t));
  sym_tab->size = table_size;
  sym_tab->hash_table = hash_tab;
  sym_tab->addr_table = addr_tab;
  return sym_tab;
}

/** @todo implement this function */
void symbol_add_unique (sym_table_t* symTab, const char* name, int addr) {
  //char* str = symTab->addr_table[addr];
  //printf("size of data at address: %d\n", sizeof(&str));
  symTab->addr_table[addr] = (char*) name;
  //printf("size of data at address: %d\n", sizeof(&symTab->addr_table[addr]));
}

/** @todo implement this function */
char* symbol_find_by_addr (sym_table_t* symTab, int addr) {
  return NULL;
}

/** @todo implement this function */
void symbol_iterate (sym_table_t* symTab, iterate_fnc_t fnc, void* data) {
}

/** @todo implement this function */
struct node* symbol_search (sym_table_t* symTab, const char* name, int* hash, int* index) {
  *hash = symbol_hash(name);
  return NULL;
}

/** @todo implement this function */
int symbol_add (sym_table_t* symTab, const char* name, int addr) {
  return 0;
}

/** @todo implement this function */
symbol_t* symbol_find_by_name (sym_table_t* symTab, const char* name) {
  return NULL;
}

/** @todo implement this function */
void symbol_reset(sym_table_t* symTab) {
}

/** @todo implement this function */
void symbol_term (sym_table_t* symTab) {
}
