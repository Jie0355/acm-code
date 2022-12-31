#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int fx(int v) {
    int cnt = 0;
    while (v) {
        v >>= 1;
        cnt ++;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;

    int arr[M];
    int maxVal = -INF;
    int ans = 0, res;

    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
        if (arr[i] < maxVal) {
            res = fx(maxVal - arr[i]);
            ans = max(ans, res);
            arr[i] = maxVal;
        }
        maxVal = max(maxVal, arr[i]);
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