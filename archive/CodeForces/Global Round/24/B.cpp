#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int n, pre, is = 0, ans = -1;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        ans = max(ans, x);
        if (!i) pre = x;
        if ((x - pre) % 5) is = 1;
    }
    if (is) cout << ans << '\n';
    else cout << ans / 5 << '\n';
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