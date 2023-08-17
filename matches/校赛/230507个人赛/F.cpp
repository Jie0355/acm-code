#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt;
    i64 ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (i * i <= n && i != 1) ans += 2;
        cnt = 0;
        for (int j = 2; j < i; j ++) {
            if ((i * i) % j == 0 && i * i / j <= n) {
                cnt ++;
            }
        }
        ans += cnt * 2 + 1;
    }

    cout << ans << '\n';

    return 0;
}
