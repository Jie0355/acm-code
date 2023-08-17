#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

void solve() {
    int n;
    cin >> n;

    int ans = 0, arr[M], diff[M];
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
        diff[i] = abs(arr[i] - i);
        if (diff[i] && !ans) ans = diff[i];
    }

    // for (int i = 1; i <= n; i ++) {
    //     cout << diff[i] << " ";
    // }

    for (int i = 1; i <= n; i ++) {
        if (diff[i]) ans = __gcd(max(ans, diff[i]), min(ans, diff[i]));
    }

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