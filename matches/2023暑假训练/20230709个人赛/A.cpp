#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 a, b;
    cin >> a >> b;

    int cnt = 0;
    for (int i = 1; i <= a; i ++) {
        if (a % i == b) {
            cout << i << " " << a / i << '\n';
            for (int j = 1; j <= (a / i) / 2; j ++) {
                if ((a / i) % j == 0) cnt ++;
            }
            cout << cnt << '\n';
            if (cnt == 282) break;
        }
    }

    return 0;
}