#include <stdio.h>
#include <stdlib.h>

#define MAXN 10005
#define MAXM 30005
#define MAXR 105
#define INF 1000000000000000000LL // 1e18

// Graph definition
int head[MAXN];
int to[MAXM], nxt[MAXM];
long long edge_fuel[MAXM];
int edge_turb[MAXM];
int edge_cnt = 0;

void add_edge(int u, int v, long long f, int t) {
    to[++edge_cnt] = v;
    edge_fuel[edge_cnt] = f;
    edge_turb[edge_cnt] = t;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt;
}

// Min-Heap for Dijkstra
typedef struct {
    long long cost;
    int u;
    int t;
} Element;

Element *heap;
int heap_sz = 0;
int heap_cap = 0;

void push(long long cost, int u, int t) {
    if (heap_sz == heap_cap) {
        heap_cap = heap_cap == 0 ? 100000 : heap_cap * 2;
        heap = (Element*)realloc(heap, heap_cap * sizeof(Element));
    }
    int i = heap_sz++;
    heap[i].cost = cost;
    heap[i].u = u;
    heap[i].t = t;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[i].cost < heap[p].cost) {
            Element tmp = heap[i];
            heap[i] = heap[p];
            heap[p] = tmp;
            i = p;
        } else {
            break;
        }
    }
}

Element pop() {
    Element res = heap[0];
    heap[0] = heap[--heap_sz];
    int i = 0;
    while (2 * i + 1 < heap_sz) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;
        if (right < heap_sz && heap[right].cost < heap[left].cost) {
            smallest = right;
        }
        if (heap[i].cost <= heap[smallest].cost) break;
        Element tmp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = tmp;
        i = smallest;
    }
    return res;
}

long long dist[MAXN][MAXR];

int main() {
    int n, m, R;
    if (scanf("%d %d %d", &n, &m, &R) != 3) return 0;

    for (int i = 1; i <= n; i++) {
        head[i] = 0;
        for (int j = 0; j <= R; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, turb;
        long long fuel;
        scanf("%d %d %lld %d", &u, &v, &fuel, &turb);
        add_edge(u, v, fuel, turb);
    }

    dist[1][0] = 0;
    push(0, 1, 0);

    while (heap_sz > 0) {
        Element curr = pop();
        long long d = curr.cost;
        int u = curr.u;
        int t = curr.t;

        if (d > dist[u][t]) continue;

        for (int e = head[u]; e; e = nxt[e]) {
            int v = to[e];
            int nturb = t + edge_turb[e];
            if (nturb <= R) {
                long long ncost = d + edge_fuel[e];
                if (ncost < dist[v][nturb]) {
                    dist[v][nturb] = ncost;
                    push(ncost, v, nturb);
                }
            }
        }
    }

    // Prefix minimum calculation to cover dynamic tolerances
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= R; j++) {
            if (dist[i][j-1] < dist[i][j]) {
                dist[i][j] = dist[i][j-1];
            }
        }
    }

    int q;
    if (scanf("%d", &q) == 1) {
        for (int i = 0; i < q; i++) {
            int dest, tol;
            scanf("%d %d", &dest, &tol);
            if (dist[dest][tol] == INF) {
                printf("-1\n");
            } else {
                printf("%lld\n", dist[dest][tol]);
            }
        }
    }

    if (heap) free(heap);
    return 0;
}
