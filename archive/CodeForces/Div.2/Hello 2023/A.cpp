#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    bool is1 = false, is2 = false;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'R' && s[i + 1] == 'L') is1 = true;
        if (s[i] == 'L' && s[i + 1] == 'R') {
            is2 = true;
            ans = i + 1;
        }
    }

    if (is1) cout << 0 << '\n';
    else {
        if (is2) cout << ans << '\n';
        else cout << -1 << '\n';
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