#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, m, d, p;
    cin >> n >> m >> d >> p;

    m -= n;
    if (!m) {
        cout << 1 << '\n';
        return;
    }

    i64 ans = (m + d * (p * p - (n + 1) * p + ((n * n) + n) / 2)) / n;
    cout << ans + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}