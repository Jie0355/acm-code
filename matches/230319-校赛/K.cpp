// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     i64 n, k;
//     cin >> n >> k;

//     map<i64, i64> imp;
//     for (int i = 0, x; i < n; i ++) {
//         cin >> x;
//         imp[x] ++;
//     }

//     i64 res = 0;
//     for (auto xi : imp) {
//         if (xi.second == 1) {
//             if (imp.find(xi.first * k) != imp.end()) {
//                 imp[xi.first * k] = 0;
//             }
//             res ++;
//         }
//     }

//     cout << res << '\n';

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

int n, k;
int arr[M];
bool vis[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i ++) vis[i] = false;

    for (int i = 0; i < n; i ++) cin >> arr[i];

    if (k == 1) {
        cout << n << '\n';
        return 0;
    }

    sort(arr, arr + n);

    int ans = 0, cnt, pos;
    for (int i = 0; i < n; i ++) {
        if (!vis[i]) {
            int xi = arr[i];
            vis[i] = true, cnt = 1;
            if (xi % k == 0) {
                int l = xi / k;
                pos = upper_bound(arr, arr + n, l) - arr - 1;
                while (pos > 0 && arr[pos] == l) {
                    vis[pos] = true;
                    cnt ++;
                    if (l % k == 0) {
                        l /= k;
                        pos = upper_bound(arr, arr + n, l) - arr - 1;
                    } else break;
                }
            }
            i64 r = xi * k;
            pos = upper_bound(arr, arr + n, r) - arr - 1;
            while (pos < n && arr[pos] == r) {
                vis[pos] = true;
                cnt ++;
                r *= k;
                pos = upper_bound(arr, arr + n, r) - arr - 1;
            }
            ans += (cnt + 1) / 2;
        }
    }

    cout << ans << '\n';

    return 0;
}