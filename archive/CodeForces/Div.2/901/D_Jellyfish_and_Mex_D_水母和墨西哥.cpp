#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> ump;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ump[x]++;
    }

    int mex = 0;
    for (int i = 0; i <= n; i++) {
        if (ump.find(i) == ump.end()) {
            mex = i;
            break;
        }
    }

    vector<int> dp(n + 1, 0);
    for (int i = mex - 1; i >= 0; i--) {
        int cnti = ump[i];
        dp[i] = (cnti - 1) * mex + i;
        for (int j = i + 1; j < mex; j++) {
            dp[i] = min(dp[i], dp[j] + (cnti - 1) * j + i);
        }
    }

    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}