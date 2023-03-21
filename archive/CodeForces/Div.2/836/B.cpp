#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e9;
void solve() {
    int n;
    cin >> n;
    if (n & 1) for (int i = 0; i < n; i ++) cout << 1 << " ";
    else {
        for (int i = 0; i < n - 2; i ++) cout << 2 << " ";
        cout << "3 1";
    }
    cout << '\n';
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