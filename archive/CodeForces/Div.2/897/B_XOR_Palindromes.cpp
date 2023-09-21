#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void pp(vector<int> &t) {
    for (int i = 0; i < t.size(); i++) cout << t[i];
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int idx = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            idx++;
            s[r] = s[l];
        }
        l++, r--;
    }

    vector<int> zz(idx, 0), oo(n + 1 - 2 * idx, 1);
    if (n & 1) {
        pp(zz);
        pp(oo);
        pp(zz);
        cout << '\n';
    } else {
        for (int i = 0; i < oo.size(); i++) {
            if (i & 1) oo[i] = 0;
        }
        pp(zz);
        pp(oo);
        pp(zz);
        cout << '\n';
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