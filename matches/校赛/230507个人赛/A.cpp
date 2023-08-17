#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    int cnt = 0, sum = 0;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        if (x == 0) {
            cnt ++;
            sum += 1;
        } else sum += x;
    }

    if (sum != 0) cout << cnt << '\n';
    else cout << cnt + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}