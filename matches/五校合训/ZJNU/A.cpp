#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    if (n <= 2) cout << 1 << '\n';
    else cout << n - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}