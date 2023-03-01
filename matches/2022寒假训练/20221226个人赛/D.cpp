#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 2e5 + 10;
int main() {
    IOS
    int n, k, arr[M];
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < k; i ++) ans += arr[i];
    int ans_t = ans;
    for (int i = k; i < n; i ++) {
        ans_t = ans_t - arr[i - k] + arr[i];
        ans = max(ans, ans_t);
    }
    double res = (ans + k) / 2.0;
    printf("%.8lf\n", res);
    return 0;
}