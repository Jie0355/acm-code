#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int maxV = ceil(1.0 * n * n / 2);

    if (k > maxV) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (k > 0 && j % 2 == i % 2) {
                    cout << "L";
                    k--;
                } else {
                    cout << "S";
                }
            }
            cout << '\n';
        }
    }

    return 0;
}