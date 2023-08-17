#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int a[M], b[M];
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    int pos = 0;
    i64 ans = 1;
    for (int i = 0; i < n; i ++) {
        while (b[pos] < a[i] && pos < n) pos ++;
        ans = ans * (pos - i) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}