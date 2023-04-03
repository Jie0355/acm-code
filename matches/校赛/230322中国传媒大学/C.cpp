#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    int sum = 0;
    unordered_map<char, int> imp;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        imp[x]++;
        sum++;
    }

    int m;
    cin >> m;

    int every = 0;
    bool is = true;
    unordered_map<char, int> t;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        for (auto xi : s) {
            if (xi == 'O') {
                every++;
                continue;
            }
            t[(char)xi]++;
        }
    }

    int cnt = sum;
    for (auto xi : t) {
        if (xi.second <= imp[xi.first]) {
            cnt -= xi.second;
        } else {
            is = false;
            break;
        }
    }

    if (every && every > cnt) is = false;

    if (is) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}