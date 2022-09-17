//849.Dijkstra求最短路I
#include <iostream>
#include <cstring>
using namespace std;
const int M = 510, INF = 0x3f3f3f3f;
int v, e, st = 1;
int Gph[M][M], dist[M];
bool vis[M];
void Dijkstra(int u) {
    memset(dist, INF, sizeof dist);
    dist[u] = 0;
    for (int i = 1; i <= v; i ++) {
        int t = -1;
        for (int j = 1; j <= v; j ++)
            if (!vis[j] && (t == -1 || dist[t] > dist[j])) t = j;
        vis[t] = true;
        for (int j = 1; j <= v; j ++)
            dist[j] = min(dist[j], dist[t] + Gph[t][j]);
    }
}
int main() {
    cin >> v >> e;
    memset(Gph, INF, sizeof Gph);
    memset(vis, false, sizeof vis)
    while (e --) {
        int a, b, w;
        cin >> a >> b >> w;
        Gph[a][b] = min(w, Gph[a][b]);
    }
    Dijkstra(st);
    if (dist[v] == INF) cout << -1;
    else cout << dist[v];
    return 0;
}
//850.Dijkstra求最短路II
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int M = 1e5 + 5e4, INF = 0x3f3f3f3f;
int v, e, st = 1;
int hd[M], wi[M], el[M], ne[M], idx = 0;
int dist[M];
bool vis[M];
void add(int a, int b, int w) {
    wi[idx] = w, el[idx] = b, ne[idx] = hd[a], hd[a] = idx ++;
}
void Dijkstra(int u) {
    memset(dist, INF, sizeof dist);
    dist[u] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        if (vis[t.second]) continue;
        vis[t.second] = true;
        for (int i = hd[t.second]; i != -1; i = ne[i]) {
            if (dist[el[i]] > dist[t.second] + wi[i]) {
                dist[el[i]] = dist[t.second] + wi[i];
                heap.push({dist[el[i]], el[i]});
            }  
        }
    }
}
int main() {
    cin >> v >> e;
    memset(hd, -1, sizeof hd);
    memset(vis, false, sizeof vis);
    while (e --) {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }
    Dijkstra(st);
    if (dist[v] == INF) cout << -1;
    else cout << dist[v];
    return 0;
}