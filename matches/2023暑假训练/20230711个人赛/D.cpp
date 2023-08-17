#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e2 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int arr[M];
    for (int i = 1; i <= n; i ++) cin >> arr[i];

    int ans = 0, did = 0;
    for (int i = 1; i <= n; i ++) {
        if (arr[i] == 0) {
            ans ++;
            did = 0;
        } else if (arr[i] == 1) {
            if (did == 2) {
                ans ++;
                did = 0;
            } else {
                did = 2;
            }
        } else if (arr[i] == 2) {
            if (did == 1) {
                ans ++;
                did = 0;
            } else {
                did = 1;
            }
        } else {
            if (did == 1) did = 2;
            else if (did == 2) did = 1;
            else {
                if (i == n) {
                    break;
                } else {
                    int j = i + 1;
                    while (arr[j] == 3 && j <= n) j ++;
                    if (j > n) break;
                    if (arr[j] == 1) did = 2;
                    else if (arr[j] == 2) did = 1;
                    else {
                        ans ++;
                        did = 0;
                    }
                    i = j;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}