#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int k, n;
    cin >> k >> n;
    int x = 1, inc = 1, maxVal = 0;
    int cnt = 0, vis[50] = {0};
    while (x <= n && cnt <= k) {
        vis[x] = 1;
        maxVal = max(maxVal, x);
        x += inc;
        inc ++; cnt ++;
    }
    if (cnt == k + 1) cnt = k;
    cnt = k - cnt;
    // cout << cnt << " ";
    int pos = maxVal + 1;
    while (cnt > 0 && pos <= n) {
        vis[pos] = 1;
        cnt --; pos ++;
    }
    pos = maxVal - 1;
    while (cnt > 0) {
        if (!vis[pos]) {
            vis[pos] = 1;
            cnt --; pos --;
        } else pos --;
    }
    for (int i = 1, t = 0; i <= n && t < k; i ++)
        if (vis[i]) {
            cout << i << " ";
            t ++;
        }
    cout << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}