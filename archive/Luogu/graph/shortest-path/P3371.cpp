#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e4 + 10, M = 5e5 + 10;
typedef pair<int, int> PII;
int vex, acs, st;
int h[M], w[M], e[M], ne[M], idx = 0;
int dist[N];
bool vis[N];
void add(int a, int b, int wi) {
    w[idx] = wi, e[idx] = b;
    ne[idx] = h[a], h[a] = idx;
    idx ++;
}
void Dijkstra(int u) {
    priority_queue<PII, vector<PII>, greater<>> heap;
    for (int i = 1; i <= vex; i ++) dist[i] = 2147483647;
    dist[u] = 0;
    heap.push({dist[u], u});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, dis = t.first;
        if (vis[ver]) continue;
        vis[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int k = e[i];
            if (dist[k] > w[i] + dis) {
                dist[k] = w[i] + dis;
                heap.push({dist[k], k});
            }
        }
    }
}
int main() {
    memset(h, -1, sizeof h);
    memset(vis, false, sizeof vis);
    cin >> vex >> acs >> st;
    while (acs --) {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }
    Dijkstra(st);
    for (int i = 1; i <= vex; i ++) cout << dist[i] << " ";
    return 0;
}