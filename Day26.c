#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200005

typedef struct {
    long long val;
    int id;
} Relic;

typedef struct {
    Relic *arr;
    int size;
    int capacity;
} MaxHeap;

int parent[MAXN];
MaxHeap heaps[MAXN];

// Returns 1 if a > b (higher value, or same value and lower ID)
int cmp(Relic a, Relic b) {
    if (a.val != b.val) return a.val > b.val ? 1 : -1;
    if (a.id != b.id) return a.id < b.id ? 1 : -1;
    return 0;
}

void push(MaxHeap *h, Relic r) {
    if (h->size == h->capacity) {
        h->capacity = h->capacity == 0 ? 4 : h->capacity * 2;
        h->arr = (Relic*)realloc(h->arr, h->capacity * sizeof(Relic));
    }
    int i = h->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (cmp(r, h->arr[p]) > 0) {
            h->arr[i] = h->arr[p];
            i = p;
        } else {
            break;
        }
    }
    h->arr[i] = r;
}

Relic pop(MaxHeap *h) {
    Relic top = h->arr[0];
    Relic last = h->arr[--h->size];
    if (h->size == 0) return top;
    
    int i = 0;
    while (i * 2 + 1 < h->size) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int largest = left;
        
        if (right < h->size && cmp(h->arr[right], h->arr[left]) > 0) {
            largest = right;
        }
        if (cmp(last, h->arr[largest]) >= 0) {
            break;
        }
        
        h->arr[i] = h->arr[largest];
        i = largest;
    }
    h->arr[i] = last;
    return top;
}

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        long long val;
        scanf("%lld", &val);
        heaps[i].size = 0;
        heaps[i].capacity = 0;
        heaps[i].arr = NULL;
        if (val > 0) {
            push(&heaps[i], (Relic){val, i});
        }
    }

    char type[10];
    for (int i = 0; i < m; i++) {
        scanf("%s", type);
        if (type[0] == 'L') { // LINK
            int u, v;
            scanf("%d %d", &u, &v);
            int root_u = find(u);
            int root_v = find(v);
            
            if (root_u != root_v) {
                // Small-to-Large Merging
                if (heaps[root_u].size < heaps[root_v].size) {
                    int temp = root_u; root_u = root_v; root_v = temp;
                }
                parent[root_v] = root_u; 
                
                // Transfer elements from smaller heap to larger heap
                for (int j = 0; j < heaps[root_v].size; j++) {
                    push(&heaps[root_u], heaps[root_v].arr[j]);
                }
                
                free(heaps[root_v].arr);
                heaps[root_v].arr = NULL;
                heaps[root_v].size = 0;
                heaps[root_v].capacity = 0;
            }
        } else if (type[0] == 'C') { // CLAIM
            int x;
            scanf("%d", &x);
            int root = find(x);
            
            if (heaps[root].size == 0) {
                printf("EMPTY\n");
            } else {
                Relic r = pop(&heaps[root]);
                printf("%d %lld\n", r.id, r.val);
            }
        }
    }
    
    // Cleanup remaining allocations
    for (int i = 1; i <= n; i++) {
        if (heaps[i].arr) free(heaps[i].arr);
    }

    return 0;
}
