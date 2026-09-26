#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 200005
#define HASH_SIZE 2097152 // 2^21

typedef struct {
    int children[26];
} TrieNode;

typedef struct {
    int node;
    long long era;
    int count;
    int used;
} HashEntry;

TrieNode trie[MAX_NODES];
int trie_node_count = 1;

HashEntry hash_table[HASH_SIZE];

// Hash function combining node_id and era
static inline unsigned int hash_func(int node, long long era) {
    unsigned long long key = ((unsigned long long)node << 32) | (unsigned long long)era;
    key = (~key) + (key << 21);
    key = key ^ (key >> 24);
    key = (key + (key << 3)) + (key << 8);
    key = key ^ (key >> 14);
    key = (key + (key << 2)) + (key << 4);
    key = key ^ (key >> 28);
    key = key + (key << 31);
    return (unsigned int)(key & (HASH_SIZE - 1));
}

void add_count(int node, long long era) {
    unsigned int idx = hash_func(node, era);
    while (hash_table[idx].used) {
        if (hash_table[idx].node == node && hash_table[idx].era == era) {
            hash_table[idx].count++;
            return;
        }
        idx = (idx + 1) & (HASH_SIZE - 1);
    }
    hash_table[idx].used = 1;
    hash_table[idx].node = node;
    hash_table[idx].era = era;
    hash_table[idx].count = 1;
}

int get_count(int node, long long era) {
    unsigned int idx = hash_func(node, era);
    while (hash_table[idx].used) {
        if (hash_table[idx].node == node && hash_table[idx].era == era) {
            return hash_table[idx].count;
        }
        idx = (idx + 1) & (HASH_SIZE - 1);
    }
    return 0;
}

void add_shard(const char *code, long long era) {
    int curr = 1;
    for (int i = 0; code[i] != '\0'; i++) {
        int idx = code[i] - 'a';
        if (trie[curr].children[idx] == 0) {
            trie[curr].children[idx] = ++trie_node_count;
        }
        curr = trie[curr].children[idx];
        add_count(curr, era);
    }
}

int query_shard(const char *prefix, long long era) {
    int curr = 1;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int idx = prefix[i] - 'a';
        if (trie[curr].children[idx] == 0) {
            return 0;
        }
        curr = trie[curr].children[idx];
    }
    return get_count(curr, era);
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    static char type[16];
    static char str[200005];
    long long era;

    for (int i = 0; i < q; i++) {
        if (scanf("%s %s %lld", type, str, &era) == 3) {
            if (type[0] == 'A') {
                add_shard(str, era);
            } else {
                printf("%d\n", query_shard(str, era));
            }
        }
    }

    return 0;
}
