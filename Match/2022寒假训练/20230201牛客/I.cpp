#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    i64 m;
    cin >> n >> m;
    m += 1;

    int ans[M];
    if (__builtin_ctzll(m) < n - 1) cout << -1 << '\n';
    else {
        for (int i = 1; i <= n; i ++) {
            if (i == n) m --;
            else m >>= 1;
            ans[i] = m;
        }
        for (int i = n; i >= 1; i --) cout << ans[i] << " ";
    }

    return 0;
}