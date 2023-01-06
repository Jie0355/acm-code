#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    if (n & 1) {
        if (n == 3) {
            cout << "NO" << '\n';
            return;
        } else cout << "YES" << '\n';
        int even = -(n / 2 - 1);
        int odd = n / 2;
        for (int i = 1; i <= n; i ++) {
            if (i & 1) cout << even << " ";
            else cout << odd << " ";
        }
    } else {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i ++) {
            if (i & 1) cout << 1 << " ";
            else cout << -1 << " ";
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}