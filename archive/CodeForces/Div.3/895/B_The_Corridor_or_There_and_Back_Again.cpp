#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    int di[110], si[110];
    for (int i = 0; i < n; i++) cin >> di[i] >> si[i];

    int ans = 500, t;
    for (int i = 0; i < n; i++) {
        t = di[i] + (si[i] - 1) / 2;
        ans = min(ans, t);
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