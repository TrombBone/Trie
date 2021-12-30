#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define UPPER_FOUR_BITS(charToUp) ((((int) charToUp) & 0xF0) >> 4)
#define LOWER_FOUR_BITS(charToLow) (((int) charToLow) & 0x0F)

typedef struct TrieNodeStruct { //~class TrieNodeStruct
    struct TrieNodeStruct *children[16];
    bool isEndOfWord; //true if last node
    int childrenCount;
} TrieNode;

TrieNode* createNode(void);
bool search(TrieNode* root, const char* key);
void insert(TrieNode* root, const char* key);
TrieNode* del(TrieNode* root, const char *key);
void display(TrieNode* root, char str[], int index, int level);
void printTrieFile(TrieNode* root, char str[], int index, int level, FILE* out);
