#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(8);

    int x, l, r;
    cin >> x >> l >> r;

    if (x <= l) cout << 0 << '\n';
    else if (x > r) cout << 1 << '\n';
    else {
        double ans = 1. * (x - l) / (r - l + 1);
        cout << ans << '\n';
    }

    return 0;
}