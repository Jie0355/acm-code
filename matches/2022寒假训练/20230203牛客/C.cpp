#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e3 + 10;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    i64 arr[M], ans[M];
    int l = 1, r = n;
    for (int i = 1; i <= n; i ++) {
        if (i & 1) {
            arr[l] = i, ans[l] = i;
            l ++;
        } else {
            arr[r] = i, ans[r] = i;
            r --;
        }
    }    

    for (int i = 1; i < n; i ++) {
        for (int j = 1; j <= n - i; j ++) {
            ans[j] = ans[j] % MOD + ans[j + 1] % MOD;
            ans[j] %= MOD;
        }
    }

    cout << ans[1] << '\n';

    for (int i = 1; i <= n; i ++)
        cout << arr[i] << " \n"[i == n];

    return 0;
}