#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;

void solve() {
    int n;
    cin >> n;

    int arr[M];
    for (int i = 1; i <= n; i ++) cin >> arr[i];

    int i = n - 1, cnt = 0;
    while (i >= 1) {
        if (arr[i] == arr[n]) i --;
        else {
            cnt ++;
            i -= n - i;
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}