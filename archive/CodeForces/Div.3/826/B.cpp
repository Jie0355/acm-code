#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        if (n == 2) cout << 2 << " " << 1;
        else if (n == 3) cout << -1;
        else {
            for (int i = n - 1; i <= n; i ++) cout << i << " ";
            for (int i = 1; i < n - 1; i ++) cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}