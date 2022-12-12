#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
const int M = 1e5 + 10;
void solve() {
    int n, arr[M], v[M];
    memset(arr, 0, sizeof arr);
    memset(v, 0, sizeof v);
    cin >> n;
    bool diff = false;
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
        v[arr[i]] ++;
        if (i != 1 && arr[i] != arr[i - 1]) diff = true;
    }
    sort(arr + 1, arr + n + 1);
    LL ans;
    if (diff) ans = 2 * ((LL)v[arr[1]] * v[arr[n]]);
    else ans = (LL)n * (n - 1);
    cout << ans << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}