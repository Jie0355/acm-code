#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 x, y, k, n, T;
    cin >> x >> y >> k >> n >> T;

    i64 i, pri = x;
    i64 sum = 0, ob = 0;
    for (i = n; i >= 1; i --) {
        sum += i * pri;
        if (sum >= T) break;
        ob += i;
        pri = x + ob / k * y;
    }

    if (!i) cout << -1 << '\n';
    else cout << n - i + 1 << '\n';
    

    return 0;
}