#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int cnt7 = 0, cnt4 = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == t[i]) continue;
        else {
            if (s[i] == '7') cnt7 ++;
            else cnt4 ++;
        }
    }

    int cnt = cnt7 + cnt4;
    cout << max(cnt7, cnt4) << '\n';

    return 0;
}