#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, k, flag = 0;
        cin >> n >> k;
        for (int i = 0; i < n;i ++) {
            int x;
            cin >> x;
            if (x) flag = 1;
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}