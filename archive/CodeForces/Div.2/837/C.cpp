#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e5 + 10;
int v[M];
void solve() {
    int n;
    cin >> n;
    int maxVal = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        maxVal = max(maxVal, x);
        for (int o = 1; o * o <= x; o ++) {
            if (!(x % o)) {
                v[o] ++;
                if (x / o != o) v[x / o] ++;
            }
        }
    }
    bool is = false;
    for (int i = maxVal; i >= 0; i --) {
        if (v[i] >= 2) {
            is = true;
            break;
        }
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