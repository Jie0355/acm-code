#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    string t(n, ' ');

    int idx = 0;
    for (int i = 0; i < s.size(); i ++) {
        t[idx ++] = s[i];
        if (t[idx - 1] == 'x' && t[idx - 2] == 'o' && t[idx - 3] == 'f')
            idx -= 3;
    }

    cout << idx << '\n';

    return 0;
}