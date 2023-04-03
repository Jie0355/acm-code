#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;
    int t = 0;
    for (auto xi : s) {
        if (xi == '0') {
            cout << (char)(t - 1 + 'a');
            t = 0;
        }
        t += xi - '0';
    }
    if (t) cout << (char)(t - 1 + 'a');
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}