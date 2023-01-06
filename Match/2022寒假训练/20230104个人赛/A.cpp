#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    int t = 3000 / x;
    if (t * x < 3000) t ++;
    
    cout << min(t, 15) << '\n';

    return 0;
}