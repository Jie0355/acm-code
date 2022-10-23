#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, nx = 1;
        string str;
        cin >> n;
        for (int i = 0; i < n; i ++) {
            char x;
            cin >> x;
            if (x == nx + '0') {
                str.push_back(x);
                nx = 1 - nx;
            }
        }
        // LL ans = 0;
        // if (str.size() & 1) ans = ((str.size() + 1) / 2 - 1) * 2;
        // else ans = ((str.size() + 1) / 2 - 1) * 2 + 1;
        // cout << ans << '\n';
        cout << str.size() - 1 << '\n';
    }
    return 0;
}