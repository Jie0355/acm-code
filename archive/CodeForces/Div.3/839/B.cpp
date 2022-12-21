#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int x1 ,x2, x3, x4;
    cin >> x1 >> x2 >> x4 >> x3;
    pair<int, int> x[5];
    x[0] = {x1, 1}; x[1] = {x2, 2};
    x[2] = {x4, 4}; x[3] = {x3, 3};
    sort(x, x + 4);
    if (x[1].second == 1 && x[2].second == 3 ||x[1].second == 3 && x[2].second == 1 || x[1].second == 2 && x[2].second == 4 || x[1].second == 4 && x[2].second == 2) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}