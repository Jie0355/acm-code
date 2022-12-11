#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 2e5 + 10;
void solve() {
    int n, x, arr[M];
    cin >> n >> x;
    if (!(n % x)) {
        arr[1] = x;
        for (int i = 2; i <= n - 1; i ++) {
            if (i == x) arr[i] = n;
            else arr[i] = i;
        }
        arr[n] = 1;
        int tx = x;
        for (int i = x + 1; i <= n - 1; i ++){
            if (!(n % i) && !(i % tx)) {
                arr[i] = n;
                arr[tx] = i;
                tx = i;
            }
        }
        for (int i = 1; i <= n; i ++) cout << arr[i] << " ";
        cout << '\n';
    } else cout << -1 << '\n';
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