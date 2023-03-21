#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e5 + 10;
void solve() {
    int n, arr[M];
    cin >> n;
    int lstVal;
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
        if (i == 1) lstVal = arr[i];
        else lstVal = __gcd(lstVal, arr[i]);
    }
    cout << arr[n] / lstVal << '\n';
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