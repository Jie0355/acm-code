#include <iostream>
#include <cstring>
using namespace std;
const int M = 510, INF = 0x3f3f3f3f;
int vex, arc;
int Gph[M][M], dis[M];
bool vis[M];
int Prim() {
    memset(dis, INF, sizeof dis);
    memset(vis, false, sizeof vis);
    for (int i = 0; i < vex; i ++) {
        int t = -1;
        for (int j = 0; j < vex; j ++)
            if (!vis[j] && (t == -1 || dis[t] < dis[j])) t = j;
        //
    }
}
int main() {
    memset(Gph, INF, sizeof Gph);
    cin >> vex >> arc;
    while (arc --) {
        int a, b, w;
        cin >> a >> b >> w;
        Gph[a][b] = Gph[b][a] = min(Gph[a][b], w);
    }
    int ans = Prim();
    if (ans == INF) cout << "Impossible" << '\n';
    else cout << ans << '\n';
    return 0;
}