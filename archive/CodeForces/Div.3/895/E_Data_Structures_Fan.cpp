#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n + 1), xors(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) xors[i] = xors[i - 1] ^ v[i];

    int xor1 = 0;
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1') xor1 ^= v[i + 1];
    }

    int query;
    cin >> query;

    while (query--) {
        int op, l, r, g;
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            xor1 = xor1 ^ (xors[r] ^ xors[l - 1]);
        } else {
            cin >> g;
            if (g == 1) cout << xor1 << " ";
            else cout << (xors[n] ^ xor1) << " ";
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}