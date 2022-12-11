#include <iostream>
#include <algorithm>
using namespace std;
const int M = 1e5 + 10;
int main() {
    int t;
    cin >> t;
    while (t --) {
        int n, fg = 0, a[M];
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> a[i];
        for (int i = 1; i < n - 1; i ++)
            if (a[i] % __gcd(a[i - 1], a[i + 1])) {fg = 1; break;}
        if (fg) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}