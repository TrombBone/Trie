#include "Trie.h"

TrieNode *createNode(void) { //fun createNode()

    TrieNode *thisNode = NULL;
    thisNode = (TrieNode *) malloc(sizeof(TrieNode));

    if (thisNode) {
        thisNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) thisNode->children[i] = NULL;
    }

    return thisNode;
}

void insert(TrieNode *root, const char *key) {
    TrieNode *thisNode = root;

    for (int i = 0; i < strlen(key); i++) {
        int index = CHAR_TO_INDEX(key[i]);
        if (!thisNode->children[index]) thisNode->children[index] = createNode();
        thisNode = thisNode->children[index];
    }

    thisNode->isEndOfWord = true;
}

bool search(TrieNode *root, const char *key) {
    TrieNode *thisNode = root;

    for (int i = 0; i < strlen(key); i++) {
        int index = CHAR_TO_INDEX(key[i]);
        if (!thisNode->children[index]) return false;
        thisNode = thisNode->children[index];
    }

    return thisNode->isEndOfWord && thisNode != NULL;
}

bool isNodeChildless(TrieNode *root) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

TrieNode *del(TrieNode *root, const char *key, int depth) {
    TrieNode *thisNode = root;

    if (!thisNode) return NULL;

    if (depth == strlen(key)) {
        thisNode->isEndOfWord = false;

        if (isNodeChildless(thisNode)) {
            free(thisNode);
            thisNode = NULL;
        }

        return thisNode;
    }

    int index = CHAR_TO_INDEX(key[depth]);
    thisNode->children[index] = del(thisNode->children[index], key, depth + 1);

    if (isNodeChildless(thisNode) && thisNode->isEndOfWord == false) {
        free(thisNode);
        thisNode = NULL;
    }

    return thisNode;
}

void display(TrieNode* root, char str[], int level) {
    if (root->isEndOfWord) {
        str[level] = '\0';
        printf("%s\n", str);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

void printTrieFile(TrieNode* root, char str[], int level, FILE *out) {
    if (root->isEndOfWord) {
        str[level] = '\n';
        str[level+1] = '\0';
        fputs(str, out);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            str[level] = i + 'a';
            printTrieFile(root->children[i], str, level + 1, out);
        }
    }
}
