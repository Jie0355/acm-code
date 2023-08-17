#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int arr[5005];
int dp[5005][5005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) dp[i][i] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            int k = j + i - 1;
            if (arr[j] > arr[k]) dp[j][k] = k - j;
            else dp[j][k] = dp[j][k - 1] + dp[j + 1][k] - dp[j + 1][k - 1];
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans += dp[i][j];

    cout << ans << '\n';

    return 0;
}