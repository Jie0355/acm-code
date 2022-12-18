#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int x[5], y[5];
    for (int i = 1; i <= 3; i ++)
        cin >> x[i] >> y[i];
    int is = 0;
    if (x[1] == x[2] || x[1] == x[3] || x[2] == x[3]) is ++;
    if (y[1] == y[2] || y[1] == y[3] || y[2] == y[3]) is ++;
    if (is <= 1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}