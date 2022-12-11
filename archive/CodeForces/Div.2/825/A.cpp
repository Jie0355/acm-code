#include <iostream>
#include <cmath>
using namespace std;
const int M = 110;
int main() {
    int t;
    cin >> t;
    while (t --) {
        int n, a[M], b[M];
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> a[i];
        for (int i = 0; i < n; i ++) cin >> b[i];
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i ++) {
            if (a[i] == b[i]) continue;
            else {
                if (!a[i]) cnt0 ++;
                else cnt1 ++;
            }
        }
        if (!cnt0 && !cnt1) cout << 0 << '\n';
        else if (!cnt0 || !cnt1) cout << max(cnt0, cnt1) << '\n';
        else if (cnt0 == cnt1) cout << 1 << '\n';
        else cout << abs(cnt0 - cnt1) + 1 << '\n';
    }
    return 0;
}