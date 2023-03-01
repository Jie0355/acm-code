#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int arr[M];
    for (int i = 1; i <= n; i ++) cin >> arr[i];

    i64 ans = 0;
    for (int i = 1; i < n; i ++) {
        if (arr[i] < arr[i + 1]) ans += arr[i + 1];
        else ans += arr[i];
    }

    cout << ans << '\n';
    
    return 0;
}