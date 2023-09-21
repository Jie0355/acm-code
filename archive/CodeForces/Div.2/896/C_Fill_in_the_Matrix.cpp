#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int M = 2e5 + 10;

vector<int> arr[M];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        arr[i].reserve(m + 1);
        for (int j = 1; j <= m; j++) arr[i][j] = 0;
    }

    if (m == 1) {
        for (int i = 0; i <= n; i++) cout << 0 << '\n';
        return;
    }

    int ans = min(n + 1, m);
    cout << ans << '\n';
    for (int i = 1; i < ans; i++) {
        int cnt = 0;
        for (int j = ans - i + 1; j <= ans; j++) {
            arr[i][j] = cnt;
            cnt++;
        }
    }

    arr[1][ans - 1] = 1;
    for (int i = 2; i <= ans - 2; i++) arr[1][i] = i;

    for (int i = 2; i < ans - 1; i++) {
        int cnt = i;
        for (int j = 2; j <= ans - i; j++) {
            arr[i][j] = cnt;
            cnt++;
        }
    }

    for (int i = 1; i < ans; i++) arr[i][1] = ans - 1;

    for (int i = 1; i < ans; i++) {
        int cnt = ans;
        for (int j = ans + 1; j <= m; j++) {
            arr[i][j] = cnt;
            cnt++;
        }
    }

    for (int i = ans; i <= n; i++) {
        for (int j = 1; j <= m; j++) { arr[i][j] = arr[i - 1][j]; }
    }
    if (ans == 3) arr[1][1] = 1, arr[1][2] = 2;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cout << arr[i][j] << " \n"[j == m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}