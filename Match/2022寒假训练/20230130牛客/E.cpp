#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, w;
    cin >> n >> t >> w;

    pair<int, int> ms[M];

    for (int i = 0; i < n; i ++) {
        int hi, vi;
        cin >> hi >> vi;
        ms[i] = {hi, vi};
    }

    i64 ans = 0;
    bool is = true;
    for (int i = 0; i < n; i ++) {
        if (ms[i].first <= w) {
            ans = ans + t;
            if (!i) ans = ans - t + 1;
        } else {
            int hi = ms[i].first, vi = ms[i].second;
            if (w > t * vi) {
                int dag = w - t * vi;
                int k = (hi - t * vi - 1) / dag;
                ans = ans + t * (k + 1);
                if (!i) ans = ans - t + 1;
            } else {
                is = false;
                break;
            }
        }
    }

    if (!is) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}