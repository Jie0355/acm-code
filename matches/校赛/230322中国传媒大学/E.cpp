#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int INF = 0x3f3f3f3f;

int g[10], ans = INF;

void op(int i) {
    g[i] = 1 - g[i];
    int l = i - 1, r = i + 1;
    int u = i - 3, d = i + 3;
    if (l % 3) g[l] = 1 - g[l];
    if ((r - 1) % 3) g[r] = 1 - g[r];
    if (u > 0) g[u] = 1 - g[u];
    if (d < 10) g[d] = 1 - g[d];
}

void DFS(int i, int cnt) {
    bool t = true;
    for (int i = 1; i <= 9; i ++) {
        if (g[i]) t = false;
    }
    if (t) {
        ans = min(ans, cnt);
        return;
    }
    if (i > 9) return;
    
    op(i);
    DFS(i + 1, cnt + 1);
    op(i);

    DFS(i + 1, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 9; i ++) cin >> g[i];

    DFS(1, 0);

    cout << ans << '\n';

    return 0;
}