#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e2 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int arr[M], sum[M]; sum[0] = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    int ans = 0;
    while (m --) {
        int l, r;
        cin >> l >> r;
        int t = sum[r] - sum[l - 1];
        if (t > 0) ans += t;
    }

    cout << ans << '\n';

    return 0;
}