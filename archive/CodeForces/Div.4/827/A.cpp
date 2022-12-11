#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x + y == z || x + z == y || y + z == x) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}