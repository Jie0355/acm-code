#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 n, x, y;
i64 res = 0x3f3f3f3f;

void DFS(i64 m, i64 cost) {
    if (m >= n) {
        res = min(res, cost + x * (m - n));
        return;
    }
    if (m + 1 == n) DFS(m + 1, cost + x);
    if (m * 2 >= n) {
        res = min(res, cost + x * (n - m)); 
        res = min(res, cost + y + x * (m * 2 - n));
        return;
    }
    DFS(m + 2, cost + 2 * x);
    DFS(2 * (m + 1), cost + x + y);
    DFS(2 * m + 1, cost + x + y);
    if (n > 2 * m && n <= 4 * m) {
        res = min(res, cost + y + x * (n - 2 * m));
        res = min(res, cost + 2 * y + x * (4 * m - n));
        return;
    } else DFS(m * 4, cost + 2 * y);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y;

    DFS(1, x);

    cout << res << '\n';

    return 0;
}