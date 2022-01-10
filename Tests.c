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
    char keys[][10] = {"a", "any", "answer"};
    TrieNode *root = createNode();

    for (int i = 0; i < 3; i++) insert(root, keys[i]);

    assert(search(root, "a"));
    assert(search(root, "any"));
    assert(search(root, "answer"));
    del(root, "a");
    assert(!search(root, "a"));
    assert(search(root, "any"));
    assert(search(root, "answer"));
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
