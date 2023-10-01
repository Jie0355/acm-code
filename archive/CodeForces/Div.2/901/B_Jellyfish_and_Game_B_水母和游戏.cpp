#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v1(n), v2(m);

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }

    for (int i = 0; i < k / 2; i++) {
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        auto v(v1);
        if (v1[0] < v2[m - 1]) swap(v1[0], v2[m - 1]);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if (v2[0] < v1[n - 1]) swap(v2[0], v1[n - 1]);
        sort(v1.begin(), v1.end());
        bool is = true;
        for (int i = 0; i < n; i++) {
            if (v1[i] != v[i]) {
                is = false;
                break;
            }
        }
        if (is) break;
    }
    if (k % 2) {
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if (v1[0] < v2[m - 1]) swap(v1[0], v2[m - 1]);
    }

    i64 ans = 0;
    for (auto xi : v1) ans += xi;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}