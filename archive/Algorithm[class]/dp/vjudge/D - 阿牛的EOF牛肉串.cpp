#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
const int M = 45;
int main() {
    IOS
    int n, cnt = 1;
    LL dp[M] = {0, 3};
    for (int i = 2; i <= 39; i ++) {
        dp[i] = 3 * dp[i - 1] - cnt;
        cnt = dp[i - 1] - cnt;
    }
    while (cin >> n) cout << dp[n] << '\n';
    return 0;
}