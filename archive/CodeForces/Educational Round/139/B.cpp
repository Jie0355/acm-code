#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int n;
    string str;
    cin >> n >> str;
    bool is = false;
    for (int i = 0; i < n; i ++) {
        int len = 0;
        for (int j = i + 1; j < n; j ++) {
            if (str[i] == str[j]) {
                int p, q;
                for (p = i, q = j; p < j && q < n; p ++, q ++) {
                    if (str[p] != str[q]) {
                        len = max(len, p - i);
                        break;
                    }
                }
                len = max(len, p - i);
            }
            if (len >= 2) {
                is = true;
                break;
            }
        }
        if (is) break;
    }
    if (is) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}