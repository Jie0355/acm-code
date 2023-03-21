#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, x;
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> x;
        cout << 3 * (10 - n) * (9 - n) << '\n';
    }   
    return 0;
}