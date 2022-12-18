#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int n, m;
    cin >> n >> m;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i ++) cin >> s[i];
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int cnt[35] = {0};
        vector<int> pos;
        for (int j = 0; j < m; j ++) {
            for (int k = i + 1; k <= n; k ++) {
                if (s[i][j] == 'o' || s[k][j] == 'o')
                    cnt[k] ++;
            }
        }
        for (int j = i + 1; j <= n; j ++)
            if (cnt[j] == m) ans ++;
    }
    cout << ans << '\n';
    return 0;
}