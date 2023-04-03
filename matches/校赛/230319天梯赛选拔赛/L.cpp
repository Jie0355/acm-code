#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    pair<int, int> w[110];
    for (int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        w[i] = {y, x};
    }

    sort(w, w + n);

    // for (int i = 0; i < n; i ++) {
    //     cout << w[i].first << " " << w[i].second << '\n';
    // }

    int exchange = -1;
    for (int i = 0; i < n; i ++) {
        if (w[i].second < s) {
            if (w[i].first == 0) exchange = max(exchange, w[i].first);
            else exchange = max(exchange, 100 - w[i].first);
        }
        else if (w[i].second == s && w[i].first == 0) exchange = max(exchange, w[i].first);
    }

    cout << exchange << '\n';

    return 0;
}