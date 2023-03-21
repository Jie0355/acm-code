#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e5 + 10;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, cnt1 = 0, arr[M];
        cin >> n;
        for (int i = 0; i < n; i ++) {
            cin >> arr[i];
            if (arr[i]) cnt1 ++;
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i --) {
            if (!cnt1) break;
            if (arr[i] == 1) cnt1 --;
            else if (cnt1) {
                cnt1 --;
                ans ++;
            }
        }
        cout << ans << '\n';
    }   
    return 0;
}