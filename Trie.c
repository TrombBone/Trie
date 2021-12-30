#include "Trie.h"

TrieNode *createNode(void) { //fun createNode()

    TrieNode *thisNode = NULL;
    thisNode = (TrieNode *) malloc(sizeof(TrieNode));

    if (thisNode) {
        thisNode->isEndOfWord = false;
        for (int i = 0; i < 16; i++) thisNode->children[i] = NULL;
        thisNode->childrenCount = 1;
    }

    return thisNode;
}

bool search(TrieNode *root, const char *key) {
    TrieNode *thisNode = root;
    TrieNode *tmpNode;

    for (int i = 0; i < strlen(key); i++) {
        // used upper four bits
        tmpNode = thisNode->children[((((int)key[i]) & 0xF0)>>4)];
        if (tmpNode != NULL) thisNode = tmpNode;
        else return NULL; // key not found

        // used lower four bits
        tmpNode = thisNode->children[((int)key[i]) & 0x0F];
        if(tmpNode != NULL) thisNode = tmpNode;
        else return(NULL); // key not found
    }

    return thisNode->isEndOfWord && thisNode != NULL;
}

void insert(TrieNode *root, const char *key) {
    TrieNode *thisNode = root;
    TrieNode *tmpNode;
    int index;

    for (int i = 0; i < 2*strlen(key); i++) {
        if(i % 2 == 0) index = (((int)key[i/2]) & 0xF0)>>4; // use upper four bits next
        else index = ((int)key[i/2]) & 0x0F; // use lower four bits next
        tmpNode = thisNode->children[index];

        if(tmpNode != NULL) thisNode = tmpNode;
        else { // need to create new node
            tmpNode = createNode();
            tmpNode->childrenCount = 0;
            thisNode->children[index] = tmpNode;
            thisNode->childrenCount += 1;
            thisNode = tmpNode;
        }
    }
    thisNode->isEndOfWord = true;
    thisNode->childrenCount += 1;
}

TrieNode *del(TrieNode *root, const char *key) {
    TrieNode *thisNode = root;
    TrieNode *tmpNode;
    TrieNode *delStartNode = root;
    int delStartPos = 0;
    int index;

    for(int i = 0; i < 2*strlen(key); i++) {
        if(i % 2 == 0) index = (((int)key[i/2]) & 0xF0)>>4; // use upper four bits
        else index = ((int)key[i/2]) & 0x0F; // use lower four bits
        tmpNode = thisNode->children[index];

        if(tmpNode != NULL) {
            if(thisNode->childrenCount > 1) {
                delStartNode = thisNode;
                delStartPos = i;
            }
            thisNode = tmpNode;
        } else return(NULL); // key did not exist
    }

    TrieNode *safeThisNode;
    if(thisNode == NULL) return(NULL); // key did not exist
    else {
        thisNode->childrenCount -= 1;
        safeThisNode = thisNode;
    }

    if(thisNode->childrenCount == 0) {
        thisNode = delStartNode;
        for(int i = delStartPos; i < 2*strlen(key); i++) {
            if(i % 2 == 0) index = (((int)key[i/2]) & 0xF0)>>4; // use upper four bits
            else index = ((int)key[i/2]) & 0x0F; // use lower four bits
            tmpNode = thisNode->children[index];
            thisNode->children[index] = NULL;
            thisNode->childrenCount -= 1;
            thisNode = tmpNode;
        }
    }
    thisNode->isEndOfWord = true;
    thisNode = NULL;

    return(safeThisNode);
}

void display(TrieNode* root, char str[], int index, int level) {
//    if (level == 0) str = (char*) malloc(sizeof(char));
//    else str = (char*) realloc(str, sizeof(char) * (level/2 + 3));
    if (root->isEndOfWord) {
        str[level/2] = '\0';
        printf("%s\n", str);
    }

    for (int i = 0; i < 16; i++) {
        if (root->children[i]) {
            if(level % 2 == 0) index = i << 4;
            else {
                index = (index & 0xF0) | i;
                str[level/2] = (char) index;
            }
            display(root->children[i], str, index, level + 1);
        }
    }
//    free(str);
}

void printTrieFile(TrieNode* root, char str[], int index, int level, FILE *out) {
    if (root->isEndOfWord) {
        str[level/2] = '\n';
        str[level/2+1] = '\0';
        fputs(str, out);
    }

    for (int i = 0; i < 16; i++) {
        if (root->children[i]) {
            if(level % 2 == 0) index = i << 4;
            else {
                index = (index & 0xF0) | i;
                str[level/2] = (char) index;
            }
            printTrieFile(root->children[i], str, index, level + 1, out);
        }
    }
}
