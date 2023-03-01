#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt_odd = 0, cnt_even = 0;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        if (x & 1) cnt_odd ++;
        else cnt_even ++;
    }

    if (abs(cnt_odd - cnt_even) <= 1) cout << "Good" << '\n';
    else cout << "Not Good" << '\n';

    return 0;
}