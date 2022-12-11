#include <iostream>
#include <algorithm>
using namespace std;
const int M = 1e5 + 10;
int main() {
    int t;
    cin >> t;
    while (t --) {
        int n, fg = 0, a[M], b[M];
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> a[i];
        for (int i = 1; i < n; i ++)
            b[i] = a[i - 1] * a[i] / __gcd(a[i - 1], a[i]);
        b[0] = a[0], b[n] = a[n - 1];
        for (int i = 0; i < n; i ++)
            if (__gcd(b[i], b[i + 1]) != a[i]) {fg = 1; break;}
        if (fg) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}