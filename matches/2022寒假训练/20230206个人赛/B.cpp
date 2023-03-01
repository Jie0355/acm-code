#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    if (n == m) {
        cout << "1.";
        for (int i = 0; i <= k; i ++)
            cout << "0\n"[i == k];
        return 0;
    }

    cout << "0.";
    for (int i = 1; i < k; i ++) {
        n *= 10;
        printf("%d", n / m);
        n %= m;
    }

    n *= 10;
    int num = n / m;
    n %= m;
    if ((n * 10) / m >= 5) num ++;

    printf("%d\n", num);

    return 0;
}