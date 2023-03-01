#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int maxVal = -INF, minVal = INF;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        maxVal = max(maxVal, x);
        minVal = min(minVal, x);
    }

    i64 ans = abs(maxVal - minVal) * n;
    cout << ans << '\n';

    return 0;
}