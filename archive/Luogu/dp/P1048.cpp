#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int dp[110][1010] = {0};
int w[110] = {0}, v[110] = {0};
int main() {
    IOS;
    int T, n;
    cin >> T >> n;
    for (int i = 1; i <= n; i ++) cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= T; j ++) {
            if (j < w[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    // for (int i = 0; i <= n; i ++)
    //     for (int j = 0; j <= T; j ++)
    //         printf("%02d%c", dp[i][j], j == T ? '\n' : ' ');
    cout << dp[n][T];
    return 0;
}