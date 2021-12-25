#include <stdio.h>
#include <stdlib.h>
#include "Trie.h"

int main(int argc, char *argv[]) {
    //"the", "a", "there", "answer", "any", "by", "bye", "their"
    FILE *inp = fopen("inp.txt", "r");
    char **keys = (char**)malloc(sizeof(char*));
    int n = 0;
    while (!feof(inp)) {
        keys[n] = (char*)malloc(sizeof(char));
        fscanf(inp,"%s", keys[n]);
        n++;
        keys = (char**)realloc(keys, sizeof(char*) * (n + 1));
    }
    fclose(inp);

    int maxKeySize = 0;
    for (int i = 0; i < n; i++) {
        int thisLen = (int) strlen(keys[i]);
        if (thisLen > maxKeySize) maxKeySize = thisLen;
//        printf("%s", keys[i]);
    }
    maxKeySize += 2;

    TrieNode *root = createNode();
    for (int i = 0; i < n; i++) insert(root, keys[i]);

    FILE *out = fopen("out.txt", "w");
    char *str = (char *) malloc(maxKeySize*sizeof(char *));

    printTrieFile(root, str, 0, out);
    display(root, str, 0);

    fclose(out);
    free(keys);
    free(str);

    return 0;
}
