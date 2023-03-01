#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;

    if (n >= 1 && n <= 7) cout << "very easy" << '\n';
    else if (n <= 233) cout << "easy" << '\n';
    else if (n <= 10032) cout << "medium" << '\n';
    else if (n <= 114514) cout << "hard" << '\n';
    else if (n <= 1919810) cout << "very hard" << '\n';
    else cout << "can not imagine" << '\n';

    return 0;
}