#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;
const i64 INF = 0x3f3f3f3f3f3f3f;

pair<i64, i64> dis[M];

void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    for (int i = 1; i <= n; i++) cin >> dis[i].first >> dis[i].second;

    i64 disA = INF, disB = INF;
    for (int i = 1; i <= k; i++) {
        disA = min(disA, abs(dis[i].first - dis[a].first) + abs(dis[i].second - dis[a].second));
        disB = min(disB, abs(dis[i].first - dis[b].first) + abs(dis[i].second - dis[b].second));
    }

    i64 ans = min(abs(dis[a].first - dis[b].first) + abs(dis[a].second - dis[b].second), disA + disB);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}