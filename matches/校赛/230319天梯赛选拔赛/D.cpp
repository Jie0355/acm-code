#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int dig[26];
    map<i64, i64> imp;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for (int i = 0; i < 26; i ++) dig[i] = 0;
        for (auto xi : s) {
            dig[xi - 'a'] ++;
        }
        i64 t = 0;
        for (int i = 0; i < 26; i ++) {
            if (dig[i] & 1) {
                t += 1 << i;
            }
        }
        imp[t] ++;
    }

    i64 ans = 0;
    for (auto xi : imp) {
        // cout << xi.first << " " << xi.second << '\n';
        ans += xi.second * (xi.second - 1) / 2;
        for (int i = 0; i < 26; i ++) {
            if (xi.first >> i & 1) {
                i64 t = xi.first ^ (1 << i);
                ans += xi.second * imp[t];
            }
        }
    }

    cout << ans << '\n';

    return 0;
}