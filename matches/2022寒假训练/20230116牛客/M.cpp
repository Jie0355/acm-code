#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 550;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(10);

    int n, m;
    cin >> n >> m;

    double dp[M][M] = {0};
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            for (int k = 0; k <= j; k ++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + (double)k / j);

    cout << dp[n][m] << '\n';

    return 0;
}