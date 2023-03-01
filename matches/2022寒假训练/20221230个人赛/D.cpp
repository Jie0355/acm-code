#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 power(i64 x, i64 y) {
    i64 res = 1;
    while (y) {
        if (y & 1) res = (i64)res * x;
        y >>= 1;
        x = (i64)x * x;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    i64 res = 1900 * m + 100 * (n - m);
    i64 ans = power(2, m);

    cout << res * ans << '\n';

    return 0;
}