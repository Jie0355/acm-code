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
        for (int i = 1; i <= n; i ++)
            if (i != 2) cout << i << " ";
        cout << 2 << '\n';
    }
    return 0;
}