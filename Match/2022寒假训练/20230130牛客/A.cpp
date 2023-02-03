#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    double xY = y * log(x);
    double yX = x * log(y);

    if (xY < yX) cout << y << '\n';
    else if (xY > yX) cout << x << '\n';
    else cout << min(x, y) << '\n';

    return 0;
}