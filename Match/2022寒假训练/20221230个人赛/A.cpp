#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int vis[M];
    vector<vector<int>> v(k + 1);

    for (int i = 1; i <= k; i ++) {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j ++) {
            int x;
            cin >> x;
            v[i].push_back(x);
            vis[x] = i;
        }
    }

    int st = 0;
    int pos = vis[1];
    for (int i = 1; i < v[pos].size(); i ++) {
        if (v[pos][i] != v[pos][i - 1] + 1) {
            st = v[pos][i - 1] + 1;
            break;
        }
    }
    if (!st) st = v[pos].back() + 1;

    int ans = 0;
    while (v[pos].back() != st - 1) {
        ans ++;
        vis[v[pos].back()] = 0;
        v[pos].pop_back();
    }

    for (int i = st; i <= n; i ++) {
        if (!vis[i]) ans ++;
        else {
            int pos = vis[i];
            while (v[pos].size()) {
                if (v[pos].back() == i) {
                    ans ++;
                    vis[i] = 0;
                    v[pos].pop_back();
                    break;
                } else {
                    ans ++;
                    vis[v[pos].back()] = 0;
                    v[pos].pop_back();
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}