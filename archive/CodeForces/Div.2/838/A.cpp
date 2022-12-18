#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int INF = 0x3f3f3f3f;
void solve() {
    int n, sum = 0;
    cin >> n;
    int ans = INF;
    for (int i = 0; i < n; i ++) {
        int x, cnt = 0;
        cin >> x;
        sum += x;
        if (x & 1) {
            while (x & 1) {
                cnt ++;
                x >>= 1;
            }
        } else {
            while (!(x & 1)) {
                cnt ++;
                x >>= 1;
            }
        }
        ans = min(ans, cnt);
    }
    if (sum & 1) cout << ans<< '\n';
    else cout << 0 << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}