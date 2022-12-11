#include <iostream>
#include <cstring>
using namespace std;
const int M = 1e3 + 10, INF = 0x3f3f3f3f;
int vex, acs, ans = 0;
int Gph[M][M], dist[M];
bool vis[M];
void reverse() {
    for (int i = 1; i <= vex; i ++)
        for (int j = i + 1; j <= vex; j ++)
            swap(Gph[i][j], Gph[j][i]);
}
void Dijkstra(int u) {
    memset(dist, INF, sizeof dist);
    memset(vis, false, sizeof vis);
    dist[u] = 0;
    for (int i = 1; i <= vex; i ++) {
        int t = -1;
        for (int j = 1; j <= vex; j ++)
            if (!vis[j] && (t == -1 || dist[t] > dist[j])) t = j;
        vis[t] = true;
        for (int j = 1; j <= vex; j ++) {
            dist[j] = min(dist[j], dist[t] + Gph[t][j]);
        }
    }
}
int main() {
    memset(Gph, INF, sizeof Gph);
    cin >> vex >> acs;
    while (acs --) {
        int a, b, w;
        cin >> a >> b >> w;
        Gph[a][b] = min(w, Gph[a][b]);
    }
    Dijkstra(1);
    for (int i = 1; i <= vex; i ++) ans += dist[i];
    reverse(); // 翻转邻接矩阵
    Dijkstra(1);
    for (int i = 1; i <= vex; i ++) ans += dist[i];
    cout << ans;
}