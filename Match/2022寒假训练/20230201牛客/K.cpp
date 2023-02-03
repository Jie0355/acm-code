#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    int ans = 0;
    i64 pre = n;
    n = n / 2 + 1;
    while (n != pre) {
        pre = n;
        n = n / 2 + 1;
        ans ++;
    }

    cout << ans << '\n';

    return 0;
}