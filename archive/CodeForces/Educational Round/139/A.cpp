#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int x;
    cin >> x;
    int dig = (int)log10(x);
    x = (int)(x / pow(10, dig)) * pow(10, dig);
    cout << 9 * dig + (int)(x / pow(10, dig)) << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}