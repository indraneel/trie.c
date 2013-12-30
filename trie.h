#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
enum { false, true };

typedef struct TrieNode* TrieNodePtr;
struct TrieNode {
    int number_of_children;
    char c;
    char *word;
    TrieNodePtr parent; 
    TrieNodePtr *children; 
    bool is_word;    
};

TrieNodePtr create_trienode(char c, TrieNodePtr parent, int num_children);
void destroy_trienode(TrieNodePtr node);

TrieNodePtr create_trie();
void build_trie(TrieNodePtr node, char *path);

#endif
