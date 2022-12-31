#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 1000000007;

void solve() {
    i64 n;
    cin >> n;

    i64 ans = n * (n + 1) % MOD * (4 * n % MOD - 1) % MOD * 337 % MOD;

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