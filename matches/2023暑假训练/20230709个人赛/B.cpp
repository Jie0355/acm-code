#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    int arr[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

    int ans = 0;
    ans = arr[n[0] - '0'] * arr[n[1] - '0'];

    cout << ans << '\n';

    return 0;
}