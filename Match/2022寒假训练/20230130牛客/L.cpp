#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

bool isTri(int a, int b, int c) {
    if ((a + b) > c && c > abs(a - b))
        if ((b + c) > a && a > abs(b - c))
            if ((a + c) > b && b > abs(a - c))
                return true;
    return false;
}

void solve() {
    int Va, Vb, Vc;
    cin >> Va >> Vb >> Vc;

    int a = (Vb + Vc - Va) / 2;
    int b = (Va + Vc - Vb) / 2;
    int c = (Va + Vb - Vc) / 2;

    if (Va == b + c && Vb == a + c && Vc == a + b) {
        if (isTri(a, b, c)) {
            cout << "Yes" << '\n';
            cout << a << " " << b << " " << c << '\n';
        } else cout << "No" << '\n';
    } else cout << "No" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}