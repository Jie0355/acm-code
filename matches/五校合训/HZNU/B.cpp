#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;

i64 arr[M], brr[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) cin >> arr[i];
    for (int i = 0; i < n; i ++) cin >> brr[i];

    sort(arr, arr + n);
    sort(brr, brr + n);

    // no reverse
    i64 now = 0, pre = 0;
    i64 ans_no_reverse = INF;
    bool is_no_reverse = true;
    for (int i = 1; i < n; i ++) {
        pre = arr[i - 1] - brr[i - 1];
        now = arr[i] - brr[i];
        if (now != pre) {
            is_no_reverse = false;
            break;
        }
    }
    if (is_no_reverse) ans_no_reverse = abs(arr[0] - brr[0]);

    // reverse (default:brr)
    for (int i = 0; i < n; i ++) brr[i] *= -1;
    sort(brr, brr + n);
    now = 0, pre = 0;
    i64 ans_reverse = INF;
    bool is_reverse = true;
    for (int i = 1; i < n; i ++) {
        pre = arr[i - 1] - brr[i - 1];
        now = arr[i] - brr[i];
        if (now != pre) {
            is_reverse = false;
            break;
        }
    }
    if (is_reverse) ans_reverse = 1 + abs(arr[0] - brr[0]);

    // cout << ans_no_reverse << " " << ans_reverse << '\n';

    if (is_no_reverse || is_reverse) cout << min(ans_no_reverse, ans_reverse) << '\n';
    else cout << -1 << '\n';

    return 0;
}