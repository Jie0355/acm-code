//C
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e6 + 7;
const int MOD = 1e9 + 7;

int main() {
    IOS;
    LL n, a, b, c, ans;
    cin >> n >> a >> b >> c;
    int res = 4 - (n % 4);
    if (res == 1) {
        ans = min(min(a, b + c), 3 * c);
        cout << ans;
    }
    else if (res == 2) {
        ans = min(min(min(2 * a, a + 3 * c), b), 2 * c);
        cout << ans;
    }
    else if (res == 3) {
        ans = min(min(a + b, 3 * a), c);
        cout << ans;
    }
    else cout << 0;
    return 0;
}