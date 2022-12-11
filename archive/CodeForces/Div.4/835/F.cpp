#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
const int M = 2e5 + 10;
void solve() {
    int n, d;
    LL c, arr[M];
    cin >> n >> c >> d;
    for (int i = 0; i < n; i ++) cin >> arr[i];
    sort(arr, arr + n, greater<LL>());
    int l = 0, r = d + 2;
    while (l < r) {
        int k = l + (r - l + 1) / 2;
        LL tot = 0;
        for (int i = 0; i < d; i ++) {
            int pos = i % k;
            if (pos < n) tot += arr[pos];
        }
        if (tot >= c) l = k;
        else r = k - 1;
    }
    if (l == d + 2) cout << "Infinity";
    else if (l == 0) cout << "Impossible";
    else cout << l - 1;
    cout << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}