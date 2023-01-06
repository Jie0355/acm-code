#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int arr[M];
    for (int i = 1; i <= n; i ++) cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    i64 sum[M]; sum[0] = 0;
    for (int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + arr[i];

    while (m --) {
        int x;
        cin >> x;
        int pos = upper_bound(arr + 1, arr + n + 1, x) - arr;
        // cout << pos << '\n';
        i64 ans = sum[pos - 1] + (i64)(n - pos + 1) * x;
        cout << ans << '\n';
    }
    
    return 0;
}