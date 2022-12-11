#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
const int M = 2e5 + 10;
int cmp(int a, int b) {
    return a > b;
}
void solve() {
    int n, x[M], v[M];
    cin >> n;
    int cnt0 = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> x[i];
        cnt0 += !x[i];
    }
    int v1 = 0, v0 = cnt0;
    LL ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (x[i]) {
            ans += v0;
            v[i] = v1 - v0;
            v1 ++;
        } else {
            v0 --;
            v[i] = v0 - v1;
        }
    }
    sort(v + 1, v + n + 1, cmp);
    if (v[1] > 0) cout << ans + v[1] << '\n';
    else cout << ans << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}