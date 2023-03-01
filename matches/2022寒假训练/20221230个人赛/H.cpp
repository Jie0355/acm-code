#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int maxVal = 0, ans;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        maxVal = maxVal > x ? maxVal : x;
        if (!i) ans = x;
        else ans = __gcd(ans, x);
    }

    int res = maxVal / ans - n;
    if (res & 1) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';

    return 0;
}