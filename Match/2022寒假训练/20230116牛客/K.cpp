#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int ans = m - (n - m) / 2 - 1;
    if (!(n - m)) ans = n - 2;
    if (ans >= 0) cout << ans << '\n';
    else cout << 0 << '\n';

    return 0;
}