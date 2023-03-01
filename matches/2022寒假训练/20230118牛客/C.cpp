#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 4e5 + 10;

pair<int, int> x[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        x[i] = {l, r};
    }

    i64 ans = 0;
    for (int i = 0; i < m; i ++) {
        for (int j = i + 1; j < m; j ++) {
            i64 l1 = x[i].first, r1 = x[i].second;
            i64 l2 = x[i].first, r2 = x[i].second;
            i64 l = n - r1, r = n - l1;
            if (l2 > r) continue;
            else {
                if (r2 < l) continue;
                else ans = (ans + min(r, r2) - max(l, l2) + 1) % 998244353;
            }
        }
    }

    cout << 2 * ans % 998244353 << '\n';

    return 0;
}