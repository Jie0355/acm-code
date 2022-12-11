#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int M = 1e5 + 10, INF = 0x3f3f3f3f;
int vex, arc, st;
int h[M], w[M], e[M], ne[M], idx = 0;
int dist[M];
bool vis[M];
void add(int a, int b, int wi) {
    w[idx] = wi, e[idx] = b;
    ne[idx] = h[a], h[a] = idx;
    idx ++;
}
void Dijkstra(int u) {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    memset(dist, INF, sizeof dist);
    dist[u] = 0;
    heap.push({0, u});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, dis = t.first;
        if (vis[ver]) continue;
        vis[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int k = e[i];
            if (dist[k] > dis + w[i]) {
                dist[k] = dis + w[i];
                heap.push({dist[k], k});
            }
        }
    }
}
int main() {
    memset(h, -1, sizeof h);
    memset(vis, false, sizeof vis);
    cin >> vex >> arc >> st;
    while (arc --) {
        int a, b, wi;
        cin >> a >> b >> wi;
        add(a, b, wi);
    }
    Dijkstra(st);
    for (int i = 1; i <= vex; i ++) {
        if (dist[i] == INF) printf("%d->%d:-1\n", st, i);
        else printf("%d->%d:%d\n", st, i, dist[i]);
    }
    return 0;
}