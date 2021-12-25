#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE (256)
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNodeStruct //~class TrieNodeStruct
{
    struct TrieNodeStruct *children[ALPHABET_SIZE];
    bool isEndOfWord; //true if last node
};

typedef struct TrieNodeStruct TrieNode;

TrieNode *createNode(void);
bool search(TrieNode *root, const char *key);
void insert(TrieNode *root, const char *key);
bool isNodeChildless(TrieNode *root);
TrieNode *del(TrieNode *root, const char *key, int depth);
void display(TrieNode* root, char str[], int level);
void printTrieFile(TrieNode* root, char str[], int level, FILE *out);
