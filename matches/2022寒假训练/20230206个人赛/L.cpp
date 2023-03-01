#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == s[0]) cnt ++;
        else break;
    }

    if (cnt == s.size()) cout << cnt - 1 << '\n';
    else cout << 2 * s.size() - cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}