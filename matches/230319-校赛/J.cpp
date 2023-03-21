#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;

int cnt = 0;
pair<int, int> ans[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    unordered_map<int, int> imp;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        imp[x] ++;
    }

    unordered_map<int, int>::iterator it = imp.begin();
    for (; it != imp.end(); ++it) {
        int count = it->second, color = it->first;
        ans[cnt ++] = {count, color};
    }

    sort(ans, ans + cnt);

    // for (int i = 0; i < cnt; i ++) {
    //     cout << ans[i].first << " " << ans[i].second << '\n';
    // }

    int res = 0;
    for (int i = 0; i < cnt - k; i ++) {
        res += ans[i].first;
    }

    cout << res << '\n';

    return 0;
}