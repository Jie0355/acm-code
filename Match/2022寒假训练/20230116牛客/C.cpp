#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        if (!x) cnt ++;
    }

    cout << n - cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}