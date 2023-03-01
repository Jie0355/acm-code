#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int x, y, i, j;
    cin >> x >> y >> i >> j;

    int ans = 0;
    double res;
    if (i < x && j < y) {
        ans = max(ans, i * j);
        ans = max(ans, (x - i) * j);
        ans = max(ans, i * (y - j));
        ans = max(ans, (x - i) * (y - j));
        res = (double)ans / (x * y);
    } else if (i >= x && j < y) {
        if (y - j > j) {
            ans = x * (y - j);
            res = (double)ans / (x * y + (i - x) * (y - j));
        } else {
            ans = x * j;
            res = (double)ans / (x * y + (i - x) * j);
        }
    } else if (i < x && j >= y) {
        if (x - i > i) {
            ans = (x - i) * y;
            res = (double)ans / (x * y + (x - i) * (j - y));
        } else {
            ans = i * y;
            res = (double)ans / (x * y + i * (j - y));
        }
    } else {
        ans = x * y;
        res = (double)ans / (i * j);
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(10) << '\n';

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}