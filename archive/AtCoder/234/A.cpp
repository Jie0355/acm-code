#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e5 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

LL func(LL x) {
    return x * x + 2 * x + 3;
}

int main() {
    IOS;
    int t;
    cin >> t;
    LL ans = func(func(func(t) + t) + func(func(t)));
    cout << ans;
    return 0;
}
