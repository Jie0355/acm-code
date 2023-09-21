#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int M = 4e4 + 10;

pair<int, int> arr[M];

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[i] = {x, i};
    }

    sort(arr + 1, arr + n + 1);

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) ans[arr[i].second] = n - i + 1;

    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}