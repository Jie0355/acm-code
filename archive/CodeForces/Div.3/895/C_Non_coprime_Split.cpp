#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int l, r;
    cin >> l >> r;

    if (l != r || r % 2 == 0) {
        if (r >= 4) cout << r / 2 << " " << r / 2 << '\n';
        else cout << -1 << '\n';
    } else {
        for (int i = 2; i * i <= r; i++) {
            if (r % i == 0) {
                cout << i << " " << r - i << '\n';
                return;
            }
        }
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}