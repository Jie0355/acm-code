#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    i64 d;
    cin >> n >> d;

    i64 arr[M];
    for (int i = 1; i <= n; i ++) cin >> arr[i];

    int pos;
    i64 ans = 0, cnt;
    for (int i = n; i >= 3; i --) {
        i64 x = arr[i] - d;
        pos = lower_bound(arr + 1, arr + n + 1, x) - arr;
        cnt = i - pos - 1;
        ans += cnt * (cnt + 1) / 2;
    }

    cout << ans << '\n';

    return 0;
}