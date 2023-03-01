#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<string> vs(n);
    unordered_map<string, int> imp;
    for (int i = 0; i < n; i ++) {
        cin >> vs[i];
        imp[vs[i]] = 1;
    }

    // for (int i = 0; i < n; i ++) cout << vs[i] << '\n';
    
    i64 ans = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            string t(k, ' ');
            for (int o = 0; o < k; o ++) {
                if (vs[i][o] == vs[j][o]) t[o] = vs[i][o];
                else if (vs[i][o] == 'E' && vs[j][o] == 'T' || vs[i][o] == 'T' && vs[j][o] == 'E') t[o] = 'S';
                else if (vs[i][o] == 'S' && vs[j][o] == 'T' || vs[i][o] == 'T' && vs[j][o] == 'S') t[o] = 'E';
                else if (vs[i][o] == 'S' && vs[j][o] == 'E' || vs[i][o] == 'E' && vs[j][o] == 'S') t[o] = 'T';
            }
            if (imp[t]) ans ++;
        }
    }
    
    cout << ans / 3 << '\n';

    return 0;
}