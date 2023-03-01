#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= pow(n, 2) - 1; i ++) {
        string t;
        cin >> t;
        for (auto xi : t) {
            if (xi == '0') cnt0 ++;
            if (xi == '1') cnt1 ++;
            if (xi == '2') cnt2 ++;
        }
    }

    string s(4, ' ');
    for (int i = 0; i <= 2; i ++) {
        s[0] = i + '0';
        for (int j = 0; j <= 2; j ++) {
            s[1] = j + '0';
            for (int p = 0; p <= 2; p ++) {
                s[2] = p + '0';
                for (int q = 0; q <= 2; q ++) {
                    s[3] = q + '0';
                    int _cnt0 = 0, _cnt1 = 0, _cnt2 = 0;
                    for (auto xi : s) {
                        if (xi == '0') _cnt0 ++;
                        if (xi == '1') _cnt1 ++;
                        if (xi == '2') _cnt2 ++;
                    }
                    if (cnt0 + _cnt0 < 4 * n) continue;
                    if (cnt1 + _cnt1 == cnt2 + _cnt2) {
                        cout << 10 - _cnt1 + _cnt2 << '\n';
                        return;
                    }
                }
            }
        }
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