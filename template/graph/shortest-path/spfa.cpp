#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int M = 1e5 + 10, INF = 0x3f3f3f3f;
int vex, acs, st;
int h[M], w[M], e[M], ne[M], idx = 0;
int dist[M];
bool vis[M];
void add(int a, int b, int wi) {
    w[idx] = wi, e[idx] = b;
    ne[idx] = h[a], h[a] = idx;
    idx ++;
}
void SPFA(int u) {
    queue<int> q;
    memset(dist, INF, sizeof dist);
    dist[u] = 0;
    q.push(u); vis[u] = true;
    while (q.size()) {
        int t = q.front();
        q.pop(); vis[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int k = e[i];
            if (dist[k] > dist[t] + w[i]) {
                dist[k] = dist[t] + w[i];
                if (!vis[k]) q.push(k); vis[k] = true;
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
    SPFA(st);
    for (int i = 1; i <= vex; i ++) {
        if (dist[i] == INF) printf("%d->%d:-1\n", st, i);
        else printf("%d->%d:%d\n", st, i, dist[i]);
    }
    return 0;
}