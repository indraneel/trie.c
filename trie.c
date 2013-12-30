#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

TrieNodePtr create_trienode(char c, TrieNodePtr parent, int num_children) {
    TrieNodePtr node = (TrieNodePtr) malloc (sizeof(struct TrieNode));
    node->c = c;
    node->parent = parent;
    node->number_of_children = num_children;
    node->children = malloc(num_children*sizeof(struct TrieNode));
    node->is_word = false;
    return node;
}

void destroy_trienode(TrieNodePtr node) {
    int i;

    if (node==NULL) {
	return;
    }

    for (i=0; i<(node->number_of_children); i++) {
	destroy_trienode((node->children[i]));
    }

    free(node->children);
    free(node);
    return;
}

TrieNodePtr get_root(TrieNodePtr node) {
    while (node->parent != NULL) {
	node = node->parent;
    }
    return node;
}
