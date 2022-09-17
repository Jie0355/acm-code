#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int M = 1e4 + 10, INF = 0x3f3f3f3f;
int v, e, st;
int head[M], wi[M], el[M], ne[M], idx = 0;
int dist[M];
bool vis[M];
void add(int a, int b, int w) {
    wi[idx] = w, el[idx] = b;
    ne[idx] = head[a], head[a] = idx;
    idx ++;
}
void Dijkstra(int u) {
    memset(dist, INF, sizeof dist);
    dist[u] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, u});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        if (vis[t.second]) continue;
        vis[t.second] = true;
        for (int i = head[t.second]; i != -1; i = ne[i]) {
            if (dist[el[i]] > dist[t.second] + wi[i]) {
                dist[el[i]] = dist[t.second] + wi[i];
                heap.push({dist[el[i]], el[i]});
            }
        }
    }
}
int main() {
    cin >> v >> e >> st;
    memset(head, -1, sizeof head);
    memset(vis, false, sizeof vis);
    while (e --) {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }
    Dijkstra(st);
    for (int i = 1; i <= v; i ++) cout << dist[i] << " ";
    return 0;
}