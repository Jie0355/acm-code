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