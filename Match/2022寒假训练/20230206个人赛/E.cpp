#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

void solve() {
    int n;
    cin >> n;

    int arr[M];
    for (int i = 1; i <= n; i ++) cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    bool is = false;
    for (int i = 1; i < n; i ++) {
        if (arr[i] == arr[i + 1] - 1 && (arr[i] ^ arr[i + 1]) == 1) {
            is = true;
            break;
        }
    }

    if (is) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}