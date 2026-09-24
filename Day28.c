#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS 20
#define MAX_ID 200005

typedef struct Node {
    int child[2];
    int active_count;
    int *heap;
    int heap_size;
    int heap_cap;
} Node;

Node *pool = NULL;
int node_count = 0;

int active_code[MAX_ID];
int is_active[MAX_ID];

int create_node() {
    int idx = ++node_count;
    pool[idx].child[0] = 0;
    pool[idx].child[1] = 0;
    pool[idx].active_count = 0;
    pool[idx].heap = NULL;
    pool[idx].heap_size = 0;
    pool[idx].heap_cap = 0;
    return idx;
}

void heap_push(Node *leaf, int id) {
    if (leaf->heap_size == leaf->heap_cap) {
        leaf->heap_cap = leaf->heap_cap == 0 ? 4 : leaf->heap_cap * 2;
        leaf->heap = (int *)realloc(leaf->heap, leaf->heap_cap * sizeof(int));
    }
    int i = leaf->heap_size++;
    leaf->heap[i] = id;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (leaf->heap[i] < leaf->heap[p]) {
            int tmp = leaf->heap[i];
            leaf->heap[i] = leaf->heap[p];
            leaf->heap[p] = tmp;
            i = p;
        } else {
            break;
        }
    }
}

void min_heapify(int *arr, int size, int i) {
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;
        if (right < size && arr[right] < arr[left]) {
            smallest = right;
        }
        if (arr[i] <= arr[smallest]) break;
        int tmp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = tmp;
        i = smallest;
    }
}

// FIX: Added expected_code to verify the ID hasn't been reassigned
int heap_get_min(Node *leaf, int expected_code) {
    while (leaf->heap_size > 0) {
        int id = leaf->heap[0];
        // Pop if inactive OR if the ID is active but broadcasting a different code now
        if (!is_active[id] || active_code[id] != expected_code) {
            leaf->heap[0] = leaf->heap[--leaf->heap_size];
            if (leaf->heap_size > 0) {
                min_heapify(leaf->heap, leaf->heap_size, 0);
            }
        } else {
            break;
        }
    }
    return leaf->heap_size > 0 ? leaf->heap[0] : -1;
}

void trie_insert(int root, int code, int id) {
    int curr = root;
    pool[curr].active_count++;
    for (int b = BITS - 1; b >= 0; b--) {
        int bit = (code >> b) & 1;
        if (!pool[curr].child[bit]) {
            pool[curr].child[bit] = create_node();
        }
        curr = pool[curr].child[bit];
        pool[curr].active_count++;
    }
    heap_push(&pool[curr], id);
}

void trie_remove(int root, int code) {
    int curr = root;
    pool[curr].active_count--;
    for (int b = BITS - 1; b >= 0; b--) {
        int bit = (code >> b) & 1;
        curr = pool[curr].child[bit];
        pool[curr].active_count--;
    }
}

void trie_query(int root, int code, int *max_xor, int *witness_id) {
    int curr = root;
    int best_code = 0;
    for (int b = BITS - 1; b >= 0; b--) {
        int bit = (code >> b) & 1;
        int desired = 1 - bit;
        if (pool[curr].child[desired] && pool[pool[curr].child[desired]].active_count > 0) {
            best_code |= (desired << b);
            curr = pool[curr].child[desired];
        } else {
            best_code |= (bit << b);
            curr = pool[curr].child[bit];
        }
    }
    *max_xor = code ^ best_code;
    
    // FIX: Pass the computed best_code so the heap can verify the active IDs
    *witness_id = heap_get_min(&pool[curr], best_code);
}

int main() {
    int m;
    if (scanf("%d", &m) != 1) return 0;

    int max_nodes = m * (BITS + 2) + 5;
    pool = (Node *)calloc(max_nodes, sizeof(Node));

    int root = create_node();

    char type[10];
    for (int i = 0; i < m; i++) {
        scanf("%s", type);
        if (strcmp(type, "ON") == 0) {
            int id, code;
            scanf("%d %d", &id, &code);
            active_code[id] = code;
            is_active[id] = 1;
            trie_insert(root, code, id);
        } else if (strcmp(type, "OFF") == 0) {
            int id;
            scanf("%d", &id);
            int code = active_code[id];
            is_active[id] = 0;
            trie_remove(root, code);
        } else if (strcmp(type, "CHECK") == 0) {
            int code;
            scanf("%d", &code);
            int max_xor = 0, witness_id = 0;
            trie_query(root, code, &max_xor, &witness_id);
            printf("%d %d\n", max_xor, witness_id);
        }
    }

    for (int i = 1; i <= node_count; i++) {
        if (pool[i].heap) free(pool[i].heap);
    }
    free(pool);

    return 0;
}
