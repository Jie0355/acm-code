#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10, INF = 0x3f3f3f3f;

typedef pair<int, int> PII;

int vex, arc;
int h[M * 2], w[M * 2], e[M * 2], ne[M * 2], idx = 0;
int dist[M], path[M], need[M];
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
        for (int i = h[ver]; ~i; i = ne[i]) {
            int k = e[i];
            if (dist[k] > dis + w[i]) {
                dist[k] = dis + w[i];
                heap.push({dist[k], k});
                path[k] = ver;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof h);
    memset(vis, false, sizeof vis);

    cin >> vex >> arc;
    
    for (int i = 0; i < arc; i ++) {
        int a, b, wi;
        cin >> a >> b >> wi;
        if (a == 1 || b == 1) need[max(a, b)] = wi;
        add(a, b, 1); add(b, a, 1);
    }

    Dijkstra(1);

    int x = vex;
    while (x) {
        if (path[x] == 1) break;
        x = path[x];
    }

    int ans;
    if (dist[vex] < arc) ans = dist[vex];
    else ans = dist[vex] + need[x] - 1;

    cout << ans << '\n';

    return 0;
}