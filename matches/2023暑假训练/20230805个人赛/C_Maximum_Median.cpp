#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int arr[M];
    for (int i = 1; i <= n; i ++) cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    i64 idx = (n + 1) / 2, ans = arr[idx];
    for (int i = idx + 1; i <= n && k; i ++) {
        i64 cost = (i64)(i - idx) * (arr[i] - arr[i - 1]);
        // cout << cost << " ";
        if (cost <= k) {
            ans = arr[i];
            k -= cost;
        } else {
            ans += k / (i - idx);
            k = 0;
        }
        // cout << ans << '\n';
    }
    if (k) ans += k / (n - idx + 1);

    cout << ans << '\n';

    return 0;
}