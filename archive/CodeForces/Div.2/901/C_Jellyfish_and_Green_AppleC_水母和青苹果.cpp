#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int n, m;
    cin >> n >> m;

    if (!(n % m)) {
        cout << 0 << '\n';
        return;
    }

    int k = gcd(n, m);
    int tM = m / k;
    while (tM % 2 == 0) {
        tM /= 2;
    }
    if (tM != 1) {
        cout << -1 << '\n';
        return;
    }

    i64 cnt = 0;
    while (n) {
        n %= m;
        cnt += n;
        n *= 2;
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}