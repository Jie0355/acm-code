#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans;
    if (a > b && a < c || a > c && a < b) cout << a << '\n';
    else if (b > a && b < c || b > c && b < a) cout << b << '\n';
    else if (c > b && c < a || c > a && c < b) cout << c << '\n';
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