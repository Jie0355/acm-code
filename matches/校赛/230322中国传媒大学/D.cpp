#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    unordered_map<i64, pair<i64, i64>> imp;
    for (int i = 0; i < n; i ++) {
        char type;
        i64 diff, cnt;
        cin >> diff >> type >> cnt;
        if (imp.find(diff) == imp.end()) {
            imp[diff] = {0, 0};
        }
        if (type == 'L') {
            imp[diff].first = cnt;
        } else if (type == 'R') {
            imp[diff].second = cnt;
        } else {
            i64 l = imp[diff].first, r = imp[diff].second;
            if (l == 0 && r == 0) {
                imp[diff].first = -cnt;
                imp[diff].second = -cnt;
            } else if (l == 0) {
                imp[diff].first = 1;
            } else if (r == 0) {
                imp[diff].second = 1;
            }
        }
    }

    i64 ans = 0;
    bool is = false;
    for (auto xi : imp) {
        i64 l = xi.second.first, r = xi.second.second;
        if (l < 0 && r < 0) {
            ans += 1;
        } else {
            ans += max(l, r);
        }
        if ((l > 0 && r > 0) || (l > 0 && r < 0) || (l < 0 && r > 0) || (l < 0 && r < 0 && abs(l) > 1)) {
            is = true;
        }
    }

    if (is) cout << ans + 1 << '\n';
    else cout << -1 << '\n';

    return 0;
}