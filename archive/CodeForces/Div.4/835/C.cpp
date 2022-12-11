#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 2e5 + 10;
int cmp(int a, int b) {
    return a > b;
}
void solve() {
    int n, arr[M], t[M];
    cin >> n;
    int tmax = 0, tpos = -1;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        t[i] = arr[i];
        if (arr[i] > tmax) {
            tmax = arr[i];
            tpos = i;
        }
    }
    sort(t, t + n, cmp);
    int maxVal = t[0], scdVal = t[1];
    for (int i = 0; i < n; i ++) {
        if (i == tpos) cout << arr[i] - scdVal << " ";
        else cout << arr[i] - maxVal << " ";
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