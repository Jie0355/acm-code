#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int n, des;
int dfs_path = INF, bfs_path = 0;
int h[2 * M], e[2 * M], ne[2 * M], idx = 0;
bool vis[M];
vector<int> ans, res;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a], h[a] = idx;
    idx ++;
}

void DFS(int u, int dis) {
    if (dis > dfs_path) return;

    if (u == des && dis < dfs_path) {
        dfs_path = dis;
        res.assign(ans.begin(), ans.end());
        return;
    }

    for (int i = h[u]; ~i; i = ne[i]) {
        int k = e[i];
        if (!vis[k]) {
            vis[k] = true;
            ans.push_back(k);

            DFS(k, dis + 1);

            vis[k] = false;
            ans.pop_back();
        }
    }

    return;
}

void BFS(int u) {
    queue<int> iq;
    iq.push(u);
    while (iq.size()) {
        int now = iq.front(); iq.pop();
        vis[now] = true;

        for (int i = h[now]; ~i; i = ne[i]) {
            int k = e[i];
            if (!vis[k]) {
                iq.push(k);
                bfs_path ++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof h);

    cin >> n >> des;
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b); add(b, a);
    }

    memset(vis, false, sizeof vis);
    ans.push_back(1);
    vis[1] = true;
    DFS(1, 0);
    // cout << dfs_path << '\n';

    memset(vis, false, sizeof vis);
    for (int i = 0; i < res.size(); i ++)
        vis[res[i]] = true;
    int x;
    for (int i = h[des]; ~i; i = ne[i]) {
        int k = e[i];
        if (vis[k]) {
            x = k;
            break;
        }
    }
    BFS(x);
    // cout << bfs_path << '\n';

    int answer = 2 * (n - 1 - dfs_path - bfs_path) + dfs_path;

    cout << answer << '\n';

    return 0;
}