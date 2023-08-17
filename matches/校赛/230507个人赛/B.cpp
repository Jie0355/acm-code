#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 110;

void solve() {
    int n;
    cin >> n;

    int arr1[M];
    int maxV = 0, pos, index;
    for (int i = 1; i <= n; i ++) {
        cin >> arr1[i];
        if (arr1[i] > maxV) {
            maxV = arr1[i];
            pos = i;
            index = 1;
        }
    }
    int arr2[M];
    for (int i = 1; i <= n; i ++) {
        cin >> arr2[i];
        if (arr2[i] > maxV) {
            maxV = arr2[i];
            pos = i;
            index = 2;
        }
    }

    maxV = 0;
    if (index == 2) swap(arr1[pos], arr2[pos]);
    for (int i = 1; i <= n; i ++) {
        if (i != pos) {
            if (arr1[i] < arr2[i]) swap(arr1[i], arr2[i]);
            maxV = max(maxV, arr2[i]);
        }
    }
    maxV = max(maxV, arr2[pos]);

    i64 ans = (i64)arr1[pos] * maxV;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}