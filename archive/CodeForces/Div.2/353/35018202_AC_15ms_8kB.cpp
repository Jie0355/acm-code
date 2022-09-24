//D
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e5 + 7;
const int MOD = 1e9 + 7;

int main() {
    IOS;
    LL ans = 0;
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int x1, x2, x3, x4;
    for (int i = 1; i <= n; i ++) {
        x2 = b - c + i;
        x3 = a - d + i;
        x4 = a + b - c - d + i;
        if (x2 >= 1 && x2 <= n && x3 >= 1 && x3 <= n && x4 >= 1 && x4 <= n) {
            ans ++;
        }
    }
    cout << ans * n;
    return 0;
}