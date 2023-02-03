#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, query;
    cin >> n >> query;

    int arr[M];
    for (int i = 1; i <= n; i ++) cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    i64 sum[M] = {0};
    for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + arr[i];

    while (query --) {
        int k, x;
        cin >> k >> x;
        int pos = upper_bound(arr + 1, arr + n + 1, x) - arr - 1;
        // cout << pos << '\n';
        int pre = pos - k;
        if (pre < 0) pre = 0;
        // cout << pre << '\n';
        i64 ans = sum[pos] - sum[pre];
        cout << ans << '\n';
    }

    return 0;
}