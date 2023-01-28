#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    if (n & 1) cout << "yukaru" << '\n';
    else cout << "kou" << '\n';

    return 0;
}