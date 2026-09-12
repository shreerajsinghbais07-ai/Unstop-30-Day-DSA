#include <stdio.h>
#include <stdlib.h>

// 1. ADDED: Define the size of the hash table
#define HASH_SIZE 10007

// 2. ADDED: Define the Linked List Node structure so the compiler knows what a "Node" is
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

int* processQueries(int queries[][3], int n, int* returnSize) {
    Node** hashTable = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    int* results = (int*)malloc(n * sizeof(int));
    int resCount = 0;

    for (int i = 0; i < n; i++) {
        int type = queries[i][0];
        int key = queries[i][1];
        int hashIdx = key % HASH_SIZE;

        if (type == 1) { 
            // INSERT OR UPDATE
            int value = queries[i][2];
            Node* curr = hashTable[hashIdx];
            int found = 0;

            while (curr != NULL) {
                if (curr->key == key) {
                    curr->value = value;
                    found = 1;
                    break;
                }
                curr = curr->next;
            }

            if (!found) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->key = key;
                newNode->value = value;
                newNode->next = hashTable[hashIdx];
                hashTable[hashIdx] = newNode;
            }
        } else if (type == 2) { 
            // GET
            Node* curr = hashTable[hashIdx];
            int foundVal = -1;
            while (curr != NULL) {
                if (curr->key == key) {
                    foundVal = curr->value;
                    break;
                }
                curr = curr->next;
            }
            results[resCount++] = foundVal;
            
        } else if (type == 3) { 
            // DELETE
            Node* curr = hashTable[hashIdx];
            Node* prev = NULL;
            while (curr != NULL) {
                if (curr->key == key) {
                    if (prev == NULL) {
                        hashTable[hashIdx] = curr->next;
                    } else {
                        prev->next = curr->next;
                    }
                    free(curr); // Free the memory to prevent leaks
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    }    

    *returnSize = resCount;
    return results;
}

int main() {
    int n;
    scanf("%d", &n);
    int queries[n][3];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &queries[i][0]);
        if (queries[i][0] == 1) {
            scanf("%d %d", &queries[i][1], &queries[i][2]);
        } else if (queries[i][0] == 2) {
            scanf("%d", &queries[i][1]);
            queries[i][2] = 0;
        } else if (queries[i][0] == 3) {
            scanf("%d", &queries[i][1]);
            queries[i][2] = 0;
        }
    }
    int returnSize;
    int* results = processQueries(queries, n, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d\n", results[i]);
    }
    free(results);
    return 0;
}
