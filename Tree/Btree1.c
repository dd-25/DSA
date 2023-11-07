#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the B-tree node structure
#define M 3 // Change M as needed for your desired order

struct BTreeNode {
    int keys[M - 1];
    struct BTreeNode *children[M];
    int num_keys;
    int leaf;
};

// Create a new B-tree node
struct BTreeNode *createNode(int leaf) {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    newNode->num_keys = 0;
    newNode->leaf = leaf;
    for (int i = 0; i < M; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Insert a key into the B-tree
void insert(struct BTreeNode *root, int key) {
    if (root->num_keys == M - 1) {
        struct BTreeNode *newNode = createNode(0);
        newNode->children[0] = root;
        splitChild(newNode, 0, root);
        insertNonFull(newNode, key);
        root = newNode;
    } else {
        insertNonFull(root, key);
    }
}

// Insert a key into a non-full B-tree node
void insertNonFull(struct BTreeNode *node, int key) {
    int i = node->num_keys - 1;
    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;
        if (node->children[i]->num_keys == M - 1) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

// Split a child node
void splitChild(struct BTreeNode *parent, int idx, struct BTreeNode *child) {
    struct BTreeNode *newChild = createNode(child->leaf);
    for (int i = 0; i < M / 2 - 1; i++) {
        newChild->keys[i] = child->keys[i + M / 2];
    }
    if (!child->leaf) {
        for (int i = 0; i < M / 2; i++) {
            newChild->children[i] = child->children[i + M / 2];
        }
    }
    child->num_keys = M / 2 - 1;
    for (int i = parent->num_keys; i > idx; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[idx + 1] = newChild;
    for (int i = parent->num_keys - 1; i >= idx; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }
    parent->keys[idx] = child->keys[M / 2 - 1];
    parent->num_keys++;
}

// Delete a key from the B-tree
void delete(struct BTreeNode *root, int key) {
    if (root == NULL) {
        return;
    }
    deleteKey(root, key);
    if (root->num_keys == 0) {
        struct BTreeNode *tmp = root;
        if (root->leaf) {
            root = NULL;
        } else {
            root = root->children[0];
        }
        free(tmp);
    }
}

// Delete a key from a B-tree node
void deleteKey(struct BTreeNode *node, int key) {
    int idx = findKeyIndex(node, key);
    if (idx < node->num_keys && node->keys[idx] == key) {
        if (node->leaf) {
            removeFromLeaf(node, idx);
        } else {
            removeFromNonLeaf(node, idx);
        }
    } else {
        if (node->leaf) {
            printf("Key %d not found in the tree.\n", key);
            return;
        }
        bool isLast = (idx == node->num_keys);
        if (node->children[idx]->num_keys < M) {
            fill(node, idx);
        }
        if (isLast && idx > node->num_keys) {
            deleteKey(node->children[idx - 1], key);
        } else {
            deleteKey(node->children[idx], key);
        }
    }
}

// Find the index of a key in a B-tree node
int findKeyIndex(struct BTreeNode *node, int key) {
    int idx = 0;
    while (idx < node->num_keys && key > node->keys[idx]) {
        idx++;
    }
    return idx;
}

// Remove a key from a leaf node
void removeFromLeaf(struct BTreeNode *node, int idx) {
    for (int i = idx + 1; i < node->num_keys; i++) {
        node->keys[i - 1] = node->keys[i];
    }
    node->num_keys--;
}

// Remove a key from a non-leaf node
void removeFromNonLeaf(struct BTreeNode *node, int idx) {
    int key = node->keys[idx];
    if (node->children[idx]->num_keys >= M) {
        int pred = getPred(node, idx);
        node->keys[idx] = pred;
        deleteKey(node->children[idx], pred);
    } else if (node->children[idx + 1]->num_keys >= M) {
        int succ = getSucc(node, idx);
        node->keys[idx] = succ;
        deleteKey(node->children[idx + 1], succ);
    } else {
        merge(node, idx);
        deleteKey(node->children[idx], key);
    }
}

// Get the predecessor of a key in a non-leaf node
int getPred(struct BTreeNode *node, int idx) {
    struct BTreeNode *curr = node->children[idx];
    while (!curr->leaf) {
        curr = curr->children[curr->num_keys];
    }
    return curr->keys[curr->num_keys - 1];
}

// Get the successor of a key in a non-leaf node
int getSucc(struct BTreeNode *node, int idx) {
    struct BTreeNode *curr = node->children[idx + 1];
    while (!curr->leaf) {
        curr = curr->children[0];
    }
    return curr->keys[0];
}

// Fill the child node that has fewer than M keys
void fill(struct BTreeNode *node, int idx) {
    if (idx != 0 && node->children[idx - 1]->num_keys >= M) {
        borrowFromPrev(node, idx);
    } else if (idx != node->num_keys && node->children[idx + 1]->num_keys >= M) {
        borrowFromNext(node, idx);
    } else {
        if (idx != node->num_keys) {
            merge(node, idx);
        } else {
            merge(node, idx - 1);
        }
    }
}

// Borrow a key from the previous child node
void borrowFromPrev(struct BTreeNode *node, int idx) {
    struct BTreeNode *child = node->children[idx];
    struct BTreeNode *sibling = node->children[idx - 1];

    for (int i = child->num_keys - 1; i >= 0; i--) {
        child->keys[i + 1] = child->keys[i];
    }

    if (!child->leaf) {
        for (int i = child->num_keys; i >= 0; i--) {
            child->children[i + 1] = child->children[i];
        }
    }

    child->keys[0] = node->keys[idx - 1];

    if (!child->leaf) {
        child->children[0] = sibling->children[sibling->num_keys];
    }

    node->keys[idx - 1] = sibling->keys[sibling->num_keys - 1];

    child->num_keys++;
    sibling->num_keys--;
}

// Borrow a key from the next child node
void borrowFromNext(struct BTreeNode *node, int idx) {
    struct BTreeNode *child = node->children[idx];
    struct BTreeNode *sibling = node->children[idx + 1];

    child->keys[child->num_keys] = node->keys[idx];

    if (!child->leaf) {
        child->children[child->num_keys + 1] = sibling->children[0];
    }

    node->keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->num_keys; i++) {
        sibling->keys[i - 1] = sibling->keys[i];
    }

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->num_keys; i++) {
            sibling->children[i - 1] = sibling->children[i];
        }
    }

    child->num_keys++;
    sibling->num_keys--;
}

// Merge a child node with the next child node
void merge(struct BTreeNode *node, int idx) {
    struct BTreeNode *child = node->children[idx];
    struct BTreeNode *sibling = node->children[idx + 1];

    child->keys[M / 2 - 1] = node->keys[idx];

    for (int i = 0; i < sibling->num_keys; i++) {
        child->keys[i + M / 2] = sibling->keys[i];
    }

    if (!child->leaf) {
        for (int i = 0; i <= sibling->num_keys; i++) {
            child->children[i + M / 2] = sibling->children[i];
        }
    }

    for (int i = idx + 1; i < node->num_keys; i++) {
        node->keys[i - 1] = node->keys[i];
    }

    for (int i = idx + 2; i <= node->num_keys; i++) {
        node->children[i - 1] = node->children[i];
    }

    child->num_keys += sibling->num_keys + 1;
    node->num_keys--;

    free(sibling);
}

// Function to print the entire B-tree
void printBTree(struct BTreeNode *node) {
    if (node != NULL) {
        int i;
        for (i = 0; i < node->num_keys; i++) {
            if (!node->leaf) {
                printBTree(node->children[i]);
            }
            printf("%d ", node->keys[i]);
        }

        if (!node->leaf) {
            printBTree(node->children[i]);
        }
    }
}

int main() {
    struct BTreeNode *root = createNode(1);

    // Insert keys
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 5);
    insert(root, 12);
    insert(root, 9);
    insert(root, 8);
    insert(root, 6);
    insert(root, 10);
    insert(root, 2);

    // Print the B-tree
    printf("B-tree after insertions: ");
    printBTree(root);
    printf("\n");

    // Delete keys
    delete(root, 6);
    delete(root, 12);

    // Print the B-tree after deletions
    printf("B-tree after deletions: ");
    printBTree(root);
    printf("\n");

    return 0;
}