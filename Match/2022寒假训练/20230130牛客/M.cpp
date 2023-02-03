#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        if (i % 3 == 0) cout << 2 << " ";
        else cout << 1 << " ";
    }

    return 0;
}