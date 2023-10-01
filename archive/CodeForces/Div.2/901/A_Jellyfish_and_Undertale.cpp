#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    i64 ans = b;
    for (int i = 0; i < n; i++) {
        ans += min(a - 1, v[i]);
    }

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