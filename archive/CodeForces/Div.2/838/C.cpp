#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
const int M = 2e5 + 10, MOD = 998244353;
void solve() {
    int n;
    LL pfx[M];
    string str;
    cin >> n;
    cin >> str;
    pfx[0] = 1;
    int sum = 1;
    for (int i = 1; i < str.size(); i ++) {
        if (str[i] == str[i - 1]) pfx[i] = 2 * pfx[i - 1] % MOD;
        else pfx[i] = 1;
        sum = (sum + pfx[i]) % MOD;
    }
    cout << sum << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}