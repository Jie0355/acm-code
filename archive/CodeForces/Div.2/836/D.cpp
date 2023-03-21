#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        int l = n - (n / 2), r = n + (n / 2);
        for (int i = l, cnt = 1; i <= r; i ++) {
            if (cnt == 1) cout << i + 1 << " ";
            else if (cnt == n || cnt == n - 1) cout << i + 3 << " ";
            else cout << i + 2 << " ";
            cnt ++;
        }
    } else {
        int l = 3 * (n / 2), r = n / 2;
        for (int i = l; i >= l - n / 2 + 1; i --) cout << i << " ";
        for (int i = r + n / 2 - 1; i >= r; i --) cout << i << " ";
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