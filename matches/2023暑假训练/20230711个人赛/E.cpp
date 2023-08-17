#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    bool vis[M];
    for (int i = 1; i <= n; i ++) vis[i] = false;

    int u[M], v[M];
    int conn[M] = {0};
    for (int i = 0; i < m; i ++) {
        cin >> u[i] >> v[i];
        conn[u[i]] ++;
        conn[v[i]] ++;
    }

    for (int i = 0; i < m; i ++) {
        int ui = u[i], vi = v[i];
        if (vis[ui] && vis[vi]) continue;
        if (conn[ui] == 1 && conn[vi] == 1) {
            if (!vis[ui] && !vis[vi]) {
                vis[vi] = true;
                conn[ui] --;
                conn[vi] --;
            } else if (!vis[ui]) {
                vis[ui] = true;
                conn[ui] --;
                conn[vi] --;
            } else if (!vis[vi]) {
                vis[vi] = true;
                conn[ui] --;
                conn[vi] --;
            }
        } else if (conn[ui] > 1 && conn[vi] == 1) {
            if (!vis[ui] && !vis[vi]) {
                vis[vi] = true;
                conn[ui] --;
                conn[vi] --;
            } else if (!vis[ui]) {
                vis[ui] = true;
                conn[ui] --;
                conn[vi] --;
            } else if (!vis[vi]) {
                vis[vi] = true;
                conn[ui] --;
                conn[vi] --;
            }
        } else if (conn[ui] == 1 && conn[vi] > 1) {
            if (!vis[ui] && !vis[vi]) {
                vis[ui] = true;
                conn[ui] --;
                conn[vi] --;
            } else if (!vis[ui]) {
                vis[ui] = true;
                conn[ui] --;
                conn[vi] --;
            } else if (!vis[vi]) {
                vis[vi] = true;
                conn[ui] --;
                conn[vi] --;
            }
        } else if (conn[ui] > 1 && conn[vi] > 1) {
            if (!vis[ui] && !vis[vi]) {
                if (conn[ui] > conn[vi]) {
                    vis[ui] = true;
                    conn[ui] --;
                    conn[vi] --;
                } else {
                    vis[vi] = true;
                    conn[ui] --;
                    conn[vi] --;
                }
            } else if (!vis[ui]) {
                vis[ui] = true;
                conn[ui] --;
                conn[vi] --;
            } else if (!vis[vi]) {
                vis[vi] = true;
                conn[ui] --;
                conn[vi] --;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) ans ++;
    }

    cout << ans << '\n';

    return 0;
}