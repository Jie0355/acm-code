#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int odd = 0, even = 0;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        if (x & 1) odd ++;
        else even ++;
    }

    cout << odd << " " << even << '\n';

    return 0;
}