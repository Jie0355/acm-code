#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e4 + 10, M = 510, INF = 0x3f3f3f3f;
struct graph {
    int a, b, w;
}Gph[N];
int v, e, st;
int dist[M], backup[M];
void Bellman_Ford(int u) {
    memset(dist, INF, sizeof dist);
    dist[u] = 0;
    int k = e; // 最多经过 k 条边的最短距离
    for (int i = 0; i < k; i ++) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < e; j ++) {
            int a = Gph[j].a, b = Gph[j].b, w = Gph[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
}
int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i ++) {
        int a, b, w;
        cin >> a >> b >> w;
        Gph[i] = {a, b, w};
    }
    cin >> st;
    Bellman_Ford(st);
    for (int i = 1; i <= v; i ++) {
        if (dist[i] > INF / 2) printf("%d->%d:-1\n", st, i);
        else printf("%d->%d:%d\n", st, i, dist[i]);
    }
    return 0;
}