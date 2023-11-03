/* The authors of this work have released all rights to it and placed it
in the public domain under the Creative Commons CC0 1.0 waiver
(http://creativecommons.org/publicdomain/zero/1.0/).
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
Retrieved from: https://literateprograms.org/hash_table__c_.html
*/

#include <stdio.h>
#include <string.h>
#include "hash_table.h"

extern FILE *yyin;
extern FILE *yyout;

static char *mystrdup(const char *s)
{
	char *b;
	if(!(b=malloc(strlen(s)+1))) return NULL;
	strcpy(b, s);
	return b;
}

static hash_size def_hashfunc(const char *key)
{
	hash_size hash=0;
	
	while(*key) hash+=(unsigned char)*key++;

	return hash;
}

HASH_TABLE *hash_table_create(hash_size size, hash_size (*hashfunc)(const char *))
{
	HASH_TABLE *hash_table;

	if(!(hash_table=malloc(sizeof(HASH_TABLE)))) return NULL;

	if(!(hash_table->nodes=calloc(size, sizeof(struct hashnode_s*)))) {
		free(hash_table);
		return NULL;
	}

	hash_table->size=size;

	if(hashfunc) hash_table->hashfunc=hashfunc;
	else hash_table->hashfunc=def_hashfunc;

	return hash_table;
}

void hash_table_destroy(HASH_TABLE *hash_table)
{
	hash_size n;
	struct hashnode_s *node, *oldnode;
	
	for(n=0; n<hash_table->size; ++n) {
		node=hash_table->nodes[n];
		while(node) {
			free(node->key);
			oldnode=node;
			node=node->next;
			free(oldnode);
		}
	}
	free(hash_table->nodes);
	free(hash_table);
}

int hash_table_insert(HASH_TABLE *hash_table, const char *key, void *data, int scope)
{
	struct hashnode_s *node;
	hash_size hash=hash_table->hashfunc(key)%hash_table->size;

	printf("HASHTBL_INSERT(): KEY = %s, HASH = %ld,  \tDATA = %s, SCOPE = %d\n", key, hash, (char*)data, scope);

	node=hash_table->nodes[hash];
	while(node) {
		if(!strcmp(node->key, key) && (node->scope == scope)) {
			node->data=data;
			return 0;
		}
		node=node->next;
	}

	if(!(node=malloc(sizeof(struct hashnode_s)))) return -1;
	if(!(node->key=mystrdup(key))) {
		free(node);
		return -1;
	}
	node->data=data;
	node->scope = scope;
	node->next=hash_table->nodes[hash];
	hash_table->nodes[hash]=node;

	return 0;
}

int hash_table_remove(HASH_TABLE *hash_table, const char *key, int scope)
{
	struct hashnode_s *node, *prevnode=NULL;
	hash_size hash=hash_table->hashfunc(key)%hash_table->size;

	node=hash_table->nodes[hash];
	while(node) {
		if((!strcmp(node->key, key)) && (node->scope == scope)) {
			free(node->key);
			if(prevnode) prevnode->next=node->next;
			else hash_table->nodes[hash]=node->next;
			free(node);
			return 0;
		}
		prevnode=node;
		node=node->next;
	}

	return -1;
}

void *hash_table_get(HASH_TABLE *hash_table, int scope)
{
	int rem;
	hash_size n;
	struct hashnode_s *node, *oldnode;
		
	for(n=0; n<hash_table->size; ++n) {
		node=hash_table->nodes[n];
		while(node) {
			if(node->scope == scope) {
				printf("HASHTBL_GET():\tSCOPE = %d, KEY = %s,  \tDATA = %s\n", node->scope, node->key, (char*)node->data);
				oldnode = node;
				node=node->next;
				rem = hash_table_remove(hash_table, oldnode->key, scope);
			}else
				node=node->next;
		}
	}
	
	if (rem == -1)
		printf("\t\t\t\t\tHASHTBL_GET():\tThere are no elements in the hash table with this scope!\n\t\tSCOPE = %d\n", scope);
	
	return NULL;
}