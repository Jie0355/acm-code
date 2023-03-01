#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

void solve() {
    int n;
    cin >> n;

    int cnt[M] = {0};
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        cnt[x] ++;
    }

    vector<int> v;
    for (int i = 1; i <= M; i ++)
        if (cnt[i]) v.push_back(cnt[i]);

    sort(v.begin(), v.end());

    int sum[M] = {0};
    for (int i = 1; i <= v.size(); i ++)
        sum[i] = sum[i - 1] + v[i - 1];

    int ans;
    for (int i = 1; i <= n; i ++) {
        int pos = upper_bound(v.begin(), v.end(), i) - v.begin();
        ans = sum[pos] + ((int)v.size() - pos) * (i - 1);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}