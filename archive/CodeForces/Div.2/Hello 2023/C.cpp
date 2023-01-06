#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;

i64 arr[M], sum[M];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    
    i64 ans = 0;

    i64 now = sum[m];
    for (int i = m - 1; i >= 1; i --) {
        if (now <= sum[i]) continue;
        else {
            ans ++;
            now = now - 2 * (sum[i + 1] - sum[i]);
        }
    }

    now = 0;
    for (int i = m + 1; i <= n; i ++) {
        if (now + arr[i] >= 0) now = now + arr[i];
        else {
            ans ++;
            now = now - arr[i];
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