#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;

int pre[M], wi[M], pos[M], cnt[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 2; i <= n; i ++) cin >> pre[i];
    for (int i = 1; i <= n; i ++) cin >> wi[i];

    memset(pos, 0, sizeof pos);
    pos[1] = 2;
    for (int i = 2; i <= n; i ++) {
        if (!pos[pre[i]]) {
            pos[pre[i]] = pos[pre[pre[i]]] + 1;
        }
    }

    // for (int i = 1; i <= n; i ++) cout << pos[i] << " ";
    // cout << '\n';

    cnt[1] = 1;
    for (int i = 2; i <= n; i ++)
        cnt[i] = pos[pre[i]];

    // for (int i = 1; i <= n; i ++) cout << cnt[i] << " ";
    // cout << '\n';

    sort(cnt + 1, cnt + n + 1);
    sort(wi + 1, wi + n + 1);
    
    i64 ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += (i64)cnt[i] * wi[i];

    cout << ans << '\n';

    return 0;
}