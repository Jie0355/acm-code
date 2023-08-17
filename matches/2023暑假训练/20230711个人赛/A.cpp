#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    b %= n;
    a += b;
    if (a > n) a %= n;
    else if (a <= 0) a += n;

    cout << a << '\n';

    return 0;
}