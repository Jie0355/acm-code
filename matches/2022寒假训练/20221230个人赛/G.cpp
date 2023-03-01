#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    int ans = 2;
    if (n == 2) ans = 1;

    for (i64 k = 2; k * k <= n; k ++) {
        i64 t = n;
        while (t >= k) t % k ? t %= k : t /= k;
        if (t == 1) ans ++;
        if (!((n - 1) % k) && k * k != n - 1) ans ++;
    }

    cout << ans << '\n';

    return 0;
}