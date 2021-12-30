#include "Tests.h"

void testInsert() {
    char key[] = "then";
    TrieNode *root = createNode();

    insert(root, key);

    assert(search(root, "then"));
    assert(!search(root, "this"));
}

void testSearch() {
    char key[] = "then";
    TrieNode *root = createNode();

    insert(root, key);

    assert(search(root, "then"));
    assert(!search(root, "this"));
}

void testDel() {
    char keys[][5] = {"then", "this"};
    TrieNode *root = createNode();

    for (int i = 0; i < ARRAY_SIZE(keys); i++) insert(root, keys[i]);

    assert(search(root, "then"));
    assert(search(root, "this"));
    del(root, "then");
    assert(!search(root, "then"));
    assert(search(root, "this"));
}

int runAllTests() {
    testInsert();
    testSearch();
    testDel();

    return 0;
}

int main() {
    runAllTests();

    return 0;
}
