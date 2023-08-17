#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 a, b;
    cin >> a >> b;

    i64 ans = 0;
    bool is;
    for (i64 i = b + 1; i <= a; i ++) {
        i64 t = i;
        while (t != 1) {
            is = false;
            for (i64 i = 2; i <= max(5, (int)sqrt(t)); i ++) {
                if (t % i == 0) {
                    t /= i;
                    ans ++;
                    is = true;
                    break;
                }
            }
            if (!is) {
                ans ++;
                break;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}