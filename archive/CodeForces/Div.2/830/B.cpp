#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, ans = 0;
        char nx[5] = {"01"};
        cin >> n;
        int t = -2;
        for (int i = 0; i < n; i ++) {
            char x;
            cin >> x;
            if (t == -2 && x == nx[1]) t = -1;
            if (t == -1 && x == nx[0]) t = 0;
            if (t >=  0 && x == nx[t]) {ans ++; t = 1 - t;}
        }
        cout << ans << '\n';
    }
    return 0;
}