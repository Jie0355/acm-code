#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int h[2 * M], e[2 * M], w[2 * M], ne[2 * M], idx = 0;
int dis[M], pre[M];
bool vis[M];

void add(int a, int b, int wi) {
    e[idx] = b, w[idx] = wi;
    ne[idx] = h[a];
    h[a] = idx;
    idx ++;
}

void Prim() {
    memset(dis, INF, sizeof dis);
    memset(vis, false, sizeof vis);

    dis[1] = 0;
    for (int i = 0; i < n; i ++) {
        int t = -1;

        for (int j = 1; j <= n; j ++)
            if (!vis[j] && (t == -1 || dis[t] < dis[j]))
                t = j;

        vis[t] = true;
        for (int j = h[t]; ~j; j = ne[j]) {
            int k = e[j];
            if (dis[k] > w[j] && vis[k]) {
                dis[k] = w[j];
                pre[k] = t;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof h);

    int l = 0, r = 0;
    cin >> n >> m;
    while (m --) {
        int a, b, wi;
        cin >> a >> b >> wi;
        if (!l && !r) l = a, r = b;
        add(a, b, wi);
        add(b, a, wi);
    }

    Prim();

    for (int i = 1; i <= n; i ++) cout << dis[i] << " \n"[i == n];
    for (int i = 1; i <= n; i ++) cout << pre[i] << " \n"[i == n];

    int maxVal = max(dis[l], dis[r]);
    for (int i = 1; i <= n; i ++)
        if (pre[i] == l || pre[i] == r)
            maxVal = max(maxVal, dis[i]);
    
    cout << maxVal << '\n';

    return 0;
}