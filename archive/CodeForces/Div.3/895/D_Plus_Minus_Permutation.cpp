#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 gcd(i64 a, i64 b) {
    return b ? gcd(b, a % b) : a;
}

i64 lcm(i64 a, i64 b) {
    return a / gcd(a, b) * b;
}

void solve() {
    i64 n, x, y;
    cin >> n >> x >> y;

    i64 cntAdd = n / x - n / lcm(x, y);
    i64 cntDiff = n / y - n / lcm(x, y);

    i64 ansAdd = cntAdd * n - cntAdd * (cntAdd - 1) / 2;
    i64 ansDiff = cntDiff + cntDiff * (cntDiff - 1) / 2;

    cout << ansAdd - ansDiff << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 t;
    cin >> t;

    while (t--) solve();

    return 0;
}