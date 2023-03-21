#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
const int M = 2e5 + 10;
void solve() {
    int n;
    map<int, int> imp;
    cin >> n;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        imp[x] ++;
    }
    LL ans = 0, sum = 0;
    for (auto xi : imp) {
        sum += xi.second;
        ans = max(ans, sum * (n - sum));
    }
    if (!ans) cout << n / 2 << '\n';
    else cout << ans << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}