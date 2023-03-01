#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        LL x, y;
        cin >> x >> y;
        LL diff = x - y;
        if (diff > 1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}