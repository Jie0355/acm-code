#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 2e5 + 10;
void solve() {
    int n, v[2][M];
    string x1, x2;
    cin >> n;
    cin >> x1 >> x2;
    for (int i = 1; i <= n; i ++) {
        if (x1[i - 1] == 'W') v[0][i] = 0;
        else v[0][i] = 1;
        if (x2[i - 1] == 'W') v[1][i] = 0;
        else v[1][i] = 1;
    }
    int pos = 1;
    while (v[0][pos] && v[1][pos]) ++ pos;
    int in;
    if (v[0][pos] == 1) in = 0;
    else in = 1;
    if (!(pos % 2)) in = 1 - in;
    int x = 1, y = in;
    bool vis[2][M], is = true;
    memset(vis, false, sizeof vis);
    while (x <= n) {
        vis[y][x] = true;
        if (v[1 - y][x] && !vis[1 - y][x]) {
            y = 1 - y;
            continue;
        }
        if (!v[y][x + 1] && x < n) {
            is = false;
            break;
        }
        x ++;
    }
    if (is) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}