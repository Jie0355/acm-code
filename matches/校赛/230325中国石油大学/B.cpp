#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct info {
    int now;
    int bas, wi, wrong;
    bool vis;
}qes[10];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++) {
        cin >> qes[i].bas >> qes[i].wi >> qes[i].wrong;
        qes[i].now = 0;
        qes[i].vis = false;
    }

    int t, idx;
    int score = 0, plus = 0;
    for (int i = 1; i <= n; i ++) {
        t = 0, idx = -1;
        for (int j = 1; j <= n; j ++) {
            if (qes[j].wi + plus <= m && !qes[j].vis) {
                qes[j].now = max(qes[j].bas * 0.3, qes[j].bas - 0.004 * qes[j].bas * (qes[j].wi + plus) - 50 * qes[j].wrong);
                if (qes[j].now > t) {
                    t = qes[j].now;
                    idx = j;
                }
            }
        }
        if (idx != -1) {
            // cout << idx << " ";
            score += qes[idx].now;
            plus += qes[idx].wi;
            qes[idx].vis = true;
        } else break;
    }

    cout << score << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --) solve();

    return 0;
}