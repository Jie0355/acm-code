#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int n;
    cin >> n;
    int dig[15] = {0};
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        for (int j = 1; j <= 10; j ++) {
            if (x & 1) dig[j] ++;
            x >>= 1;
        }
    }
    // for (int i = 1; i <= 10; i ++) cout << dig[i] << " ";
    int maxVal[15], minVal[15];
    for (int i = 1; i <= 10; i ++) {
        if (dig[i]) maxVal[i] = 1;
        else maxVal[i] = 0;
        if (n - dig[i]) minVal[i] = 0;
        else minVal[i] = 1;
    }
    int maxv = 0, minv = 0;
    for (int i = 1; i <= 10; i ++) {
        if (maxVal[i]) maxv += pow(2, i - 1);
        if (minVal[i]) minv += pow(2, i - 1);
    }
    cout << maxv - minv << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}