#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    int u[M], v[M], w[M];
    for (int i = 1; i <= n; i ++) w[i] = INF;
    for (int i = 0, wi; i < m; i ++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    if (!k) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> des;
    for (int i = 0, x; i < k; i ++) {
        cin >> x;
        des.push_back(x);
    }

    sort(des.begin(), des.end());

    int ans = INF;
    for (int i = 0; i < m; i ++) {
        int x = u[i], y = v[i], cost = w[i];
        if (*lower_bound(des.begin(), des.end(), x) != x && *lower_bound(des.begin(), des.end(), y) == y) ans = min(ans, cost);
        if (*lower_bound(des.begin(), des.end(), x) == x && *lower_bound(des.begin(), des.end(), y) != y) ans = min(ans, cost);
    }

    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}