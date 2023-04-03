#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;

int pos[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, d;
    cin >> n >> m >> s >> d;

    for (int i = 1; i <= n; i ++) {
        cin >> pos[i];
    }

    sort(pos + 1, pos + n + 1);

    int now = 0;
    vector<int> ans;
    bool is = true;

    for (int i = 1; i <= n; i ++) {
        if (pos[i] - now - 1 >= s) {
            ans.push_back(pos[i] - now - 1);
            now = pos[i] - 1;
            if (i < n) {
                if (pos[i + 1] - pos[i] - 2 >= s) {
                    ans.push_back(2);
                    now = pos[i] + 1;
                } else {
                    int j;
                    for (j = i + 1; j <= n; j ++) {
                        if (pos[j] - pos[i] + 2 > d) break;
                        if (pos[j] - pos[j - 1] - 2 >= s) break;
                    }
                    ans.push_back(pos[j - 1] - pos[i] + 2);
                    now = pos[j - 1] + 1;
                    i = j - 1;
                }
            } else {
                ans.push_back(2);
                now = pos[n] + 1;
                if (now != m) {
                    ans.push_back(m - now);
                    now = m;
                }
            }
        } else {
            is = false;
            break;
        }
    }
    if (now != m) ans.push_back(m - now);

    if (!is){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    for (int i = 0; i < ans.size(); i ++) {
        if (i & 1) cout << "JUMP " << ans[i] << '\n';
        else cout << "RUN " << ans[i] << '\n';
    }

    return 0;
}