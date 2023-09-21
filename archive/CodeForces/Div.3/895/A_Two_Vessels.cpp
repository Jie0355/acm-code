#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = ((abs(a - b) + 1) / 2 + c - 1) / c;
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