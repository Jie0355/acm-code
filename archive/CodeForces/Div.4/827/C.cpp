#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int next = 0;
        char G[15][15];
        for (int i = 1; i <= 8; i ++)
            for (int j = 1; j <= 8; j ++)
                cin >> G[i][j];
        for (int i = 1; i <= 8; i ++) {
            int flag = 1;
            char x = 'R';
            if (x == 'B' || x == '.') continue;
            for (int j = 2; j <= 8; j ++)
                if (G[i][j] != x) {flag = 0; break; }
            if (flag) {cout << x << '\n'; next = 1; break; }
        }
        if (!next) cout << 'B' << '\n';
    }
    return 0;
}