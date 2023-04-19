#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int i = 0, lenth = s.size();
    bool minus = false, even = false;
    if (s[0] == '-') {
        i ++, lenth --;
        minus = true;
    }

    int cnt = 0;
    for (; i < s.size(); i ++) {
        if (s[i] == '2') cnt ++;
        if (i == s.size() - 1 && !((s[i] - '0') % 2)) {
            even = true;
        }
    }

    double ans = 1.0 * cnt / lenth;
    if (minus) ans *= 1.5;
    if (even) ans *= 2.0;

    printf("%.2lf%%", ans * 100);

    return 0;
}