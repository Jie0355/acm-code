#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 k, a, b;
    cin >> k >> a >> b;

    i64 ans = 0;
    if (a <= 0 && b >= 0)
        ans = -a / k + b / k + 1;
    else if (a > 0)
        ans = b / k - (a - 1) / k;
    else if (b < 0)
        ans = -a / k - (-b - 1) / k;

    cout << ans << '\n';

    return 0;
}