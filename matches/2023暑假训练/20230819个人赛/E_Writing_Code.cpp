#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int M = 5e2 + 10;

i64 dp[M][M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, v, p;
    cin >> n >> m >> v >> p;

    int bugs[M];
    for (int i = 1; i <= n; i++) cin >> bugs[i];

    for (int k = 0; k <= v; k++) dp[0][k] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = bugs[i]; k <= v; k++) dp[j][k] = (dp[j][k] + dp[j - 1][k - bugs[i]]) % p;

    cout << dp[m][v] << '\n';

    return 0;
}