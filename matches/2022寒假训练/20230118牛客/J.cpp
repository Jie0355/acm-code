#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    i64 sum = 0;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        x = abs(x);
        sum += x;
    }

    cout << sum * 2 * n << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}