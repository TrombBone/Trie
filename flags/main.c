#include <stdio.h>
#include <stdlib.h>
#include "Trie.h"

/*
 * Программа создаёт префиксное дерево из слов, поданных в входном файле (1-й аргумент).
 * Концом входного файла является пустая строка.
 * На выходе выдаёт файл (2-й аргумент) с деревом в виде списка слов, перечисленных в порядке,
 * в котором они находятся в дереве (по сути в алфавитном).
 *
 * //cd C:\<your_path>\Trie\cmake-build-debug
 * //Trie.exe inp.txt out.txt
 */
int main(int argc, char *argv[]) {
//    if (argc != 2) {
//        printf("\nWrong command line arguments\n");
//        return -1;
//    }

    //"the", "a", "there", "answer", "any", "by", "bye", "their"
    FILE *inp = fopen(argv[1], "r");
//    FILE *inp = fopen("inp.txt", "r");

    char **keys = (char**)malloc(sizeof(char*));

    int n = 0;
    int partsWordCounter = 0;
    int memoryAlloc = 256;
    char *tmpKey = (char*)malloc(sizeof(char)*memoryAlloc);
    bool isEndWord = true;

    while (!feof(inp)) {
        if (isEndWord) keys[n] = (char*)malloc(sizeof(char)*memoryAlloc);
        else keys[n] = (char*)realloc(keys[n], sizeof(char)*memoryAlloc*(partsWordCounter+1)+1);

        fgets(tmpKey, memoryAlloc+1, inp);

        int keySize = strlen(tmpKey);

        for (int i = 0; i < keySize; i++) {
            keys[n][i+memoryAlloc*partsWordCounter] = tmpKey[i];
            if (tmpKey[i] == '\n') {
                keys[n][i+memoryAlloc*partsWordCounter + 1] = '\0';
                break;
            }
        }

        if (tmpKey[keySize - 1] != '\n') {
            isEndWord = false;
//            printf("%s\n", keys[n]);
            partsWordCounter += 1;
        } else {
            isEndWord = true;
            partsWordCounter = 0;
        }

        if (isEndWord) {
            n++;
            keys = (char**)realloc(keys, sizeof(char*) * (n + 1));
        }
    }
    fclose(inp);

    int maxKeySize = 0;
    for (int i = 0; i < n-1; i++) {
        int thisLen = (int) strlen(keys[i]);
        if (thisLen > maxKeySize) maxKeySize = thisLen;
        int keyLen = strlen(keys[i]);
        keys[i][keyLen-1] = '\0';
//        printf("%s", keys[i]);
    }
    maxKeySize += 2;

    TrieNode *root = createNode();
    for (int i = 0; i < n; i++) insert(root, keys[i]);

    FILE *out = fopen(argv[2], "w");
//    FILE *out = fopen("out.txt", "w");
    char *str = (char *) malloc(maxKeySize*sizeof(char *));

    printTrieFile(root, str, 0, out);
    display(root, str, 0);

    fclose(out);
    free(keys);
    free(str);

    return 0;
}
