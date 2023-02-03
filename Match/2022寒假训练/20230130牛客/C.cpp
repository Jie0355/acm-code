#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 110;

int n, c;
i64 w[M], v[M];
i64 dp1[M][M][M] = {0}, dp2[M][M][M] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
	for (int i = 1; i <= n; i ++) cin >> w[i] >> v[i];

    i64 maxVal = 0;
    for (int k = 1; k <= n; k ++) {
        int now_bag = c - w[k];
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= now_bag; j ++) {
                if (i == k) dp1[k][i][j] = dp1[k][i - 1][j];
                else {
                    if (j < w[i]) dp1[k][i][j] = dp1[k][i - 1][j];
                    else dp1[k][i][j] = max(dp1[k][i - 1][j], dp1[k][i - 1][j - w[i]] + v[i]);
                }
            }
            for (int j = 1; j <= c; j ++) {
                if (i == k) dp2[k][i][j] = dp2[k][i - 1][j];
                else {
                    if (j < w[i]) dp2[k][i][j] = dp2[k][i - 1][j];
                    else dp2[k][i][j] = max(dp2[k][i - 1][j], dp2[k][i - 1][j - w[i]] + v[i]);
                }
            }
        }
        maxVal = max(maxVal, dp1[k][n][c - w[k]] + v[k]);
    }

    // cout << maxVal << '\n';
    // for (int i = 1; i <= n; i ++) {
    //     cout << dp2[i][n][c] << " " << dp1[i][n][c - w[i]] + v[i] << '\n';
    // }

	for (int i = 1; i <= n; i ++) {
        if (dp2[i][n][c] < maxVal) cout << 0 << '\n';
        else {
            i64 ans = maxVal - (dp1[i][n][c - w[i]] + v[i]) + 1;
            cout << ans << '\n';
        }
    }

    return 0;
}