#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    while (n && m) {
        if (n > m) {
            n -= 2;
            m -= 1;
        } else if (n < m) {
            n -= 1;
            m -= 2;
        } else if (n == 1 && m == 1) break;
        else {
            n -= 1;
            m -= 2;
        }
        ans ++;
    }

    cout << ans << '\n';

    return 0;
}