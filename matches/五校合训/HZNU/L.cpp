#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, k;
    cin >> m >> k;

    int w[10];
    for (int i = 1; i <= 5; i ++) cin >> w[i];

    int v[10];
    for (int i = 1; i <= 5; i ++) cin >> v[i];

    int arr[5] = {1, 2, 3, 4, 5};
    double ans = 0;
    do {
        int price = 0, value = 0;
        double t;
        for (int i = 0; i < 5; i ++) {
            price += w[arr[i]];
            value += v[arr[i]];
            if (price >= m) t = 1.0 * value / (price - k);
            else t = 1.0 * value / price;
            ans = max(ans, t);
        }
    } while (next_permutation(arr, arr + 5));

    cout << fixed << setprecision(2) << ans << '\n';

    return 0;
}