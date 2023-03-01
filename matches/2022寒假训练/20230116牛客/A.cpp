#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;

    int cntA = 0, cntB = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (i & 1 && s[i] == '1') cntB ++;
        if (!(i & 1) && s[i] == '1') cntA ++;  
    }

    if (cntA == cntB) cout << -1 << '\n';
    else {
        cntA = 0, cntB = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (i & 1 && s[i] == '1') cntB ++;
            if (!(i & 1) && s[i] == '1') cntA ++;
            if (!(i & 1) && (cntA > cntB + (10 - i) / 2 || cntB > cntA + (9 - i) / 2)) {
                cout << i + 1 << '\n';
                return;
            }
            if (i & 1 && (cntB > cntA + (9 - i) / 2 || cntA > cntB + (9 - i) / 2)) {
                cout << i + 1 << '\n';
                return;
            }
        }
        cout << 10 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}