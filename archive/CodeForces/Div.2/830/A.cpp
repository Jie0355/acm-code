#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
int isPrime(int x) {
    if (x == 2) return 0;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return 0;
    return x;
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, arr[25];
        cin >> n;
        for (int i = 1; i <= n; i ++) cin >> arr[i];
        if (n == 1) {
            if (isPrime(arr[n])) {
                cout << 0 << '\n';
                continue;
            }
            else {
                cout << 1 << '\n';
                continue;
            }
        }
        int nx1 = 0;
        for (int i = 1; i < n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                if (__gcd(arr[i], arr[j]) == 1) {
                    cout << 0 << '\n';
                    nx1 = 1; break;
                }
            }
            if (nx1) break;
        }
        if (nx1) continue;
        int cost, ans = INF;
        for (int i = n; i > 1; i --) {
            cost = 0;
            for (int j = i - 1; j > 0; j --) {
                if (__gcd(__gcd(arr[i], i), arr[j]) == 1) {
                    cost = n - i + 1;
                    break;
                }
                else if (__gcd(arr[i], __gcd(arr[j], j)) == 1) {
                    cost = n - j + 1;
                    break;
                }
                else if (__gcd(__gcd(arr[i], i), __gcd(arr[j], j)) == 1) {
                    cost = n - i + 1 + n - j + 1;
                    break;
                }
            }
            if (cost) ans = min(ans, cost);
        }
        cout << ans << '\n';
    }
    return 0;
}