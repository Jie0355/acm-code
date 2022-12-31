#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    i64 mul = 1;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        mul *= x;
    }

    i64 ans = 2022 * (mul + n - 1);
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