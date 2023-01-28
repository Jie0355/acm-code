#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    i64 sum = 0;
    for (int i = 0; i < n; i ++) {
        i64 x;
        cin >> x;
        if (x > 0 && x % 2 == 0)
            sum += x / (pow(2, __builtin_ctz(x)));
        else sum += x;
    }

    cout << sum << '\n';

    return 0;
}