#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main() {
    IOS;
    int n, m, x, tmp = 1;
    ll loop = 0, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> x;
        if (x < tmp) loop ++;
        tmp = x;
    }
    ans = n * loop + x - 1;
    cout << ans;
    return 0;
}