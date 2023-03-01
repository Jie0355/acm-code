#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n;
    cin >> n;

    i64 l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    i64 l = n - r1, r = n - l1, ans;
    if (l2 > r) ans = 0;
    else {
        if (r2 < l) ans = 0;
        else ans = min(r, r2) - max(l, l2) + 1;
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