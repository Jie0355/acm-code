#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

set<int> s;

void solve() {
    int n;
    cin >> n;

    s.clear();
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    int mex = 0;
    for (auto xi : s) {
        if (xi == mex) mex++;
        else break;
    }

    cout << mex << '\n';
    cout.flush();

    while (1) {
        int y;
        cin >> y;
        if (y >= 0) {
            cout << y << '\n';
            cout.flush();
        } else {
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}