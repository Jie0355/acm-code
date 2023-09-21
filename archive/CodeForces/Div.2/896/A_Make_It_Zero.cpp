#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    for (int i = 0, x; i < n; i++) cin >> x;

    if (n & 1) {
        cout << 4 << '\n';
        cout << 1 << " " << n << '\n';
        cout << 1 << " " << n - 1 << '\n';
        cout << n - 1 << " " << n << '\n';
        cout << n - 1 << " " << n << '\n';
    } else {
        cout << 2 << '\n';
        cout << 1 << " " << n << '\n';
        cout << 1 << " " << n << '\n';
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