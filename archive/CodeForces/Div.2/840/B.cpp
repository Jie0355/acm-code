#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
const int M = 1e5 + 10;
void solve() {
    int n; LL k;
    cin >> n >> k;
    pair<LL, LL> arr[M];
    LL hi[M], pi[M];
    for (int i = 1; i <= n; i ++) cin >> hi[i];
    for (int i = 1; i <= n; i ++) cin >> pi[i];
    for (int i = 1; i <= n; i ++) arr[i] = {hi[i], pi[i]};
    sort(arr + 1, arr + n + 1);
    LL now = k;
    bool is;
    while (1) {
        if (k >= arr[n].first) {
            is = true;
            break;
        }
        if (now <= 0) {
            is = false;
            break;
        }
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid].first <= k) l = mid + 1;
            else r = mid - 1;
        }
        // if (l == n) {
        //     is = true;
        //     break;
        // }
        int minPi = arr[l].second;
        for (int pos = l + 1; pos <= n; pos ++)
            if (arr[pos].second < minPi) minPi = arr[pos].second;
        if (now - minPi <= 0) {
            is = false;
            break;
        }
        now = now - minPi;
        k += now;
    }
    if (is == true) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}