#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 a, b, c;
    cin >> a >> b >> c;
    
    i64 aa = a * (a + 1) / 2 % MOD;
    i64 bb = b * (b + 1) / 2 % MOD;
    i64 cc = c * (c + 1) / 2 % MOD;
    i64 ans = aa * bb % MOD * cc % MOD;

    cout << ans << '\n';

    return 0;
}