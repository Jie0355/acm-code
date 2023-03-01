#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 55;

int n, m;
char G[M][M];

bool check(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    int dirx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int diry[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> G[i][j];
            if (G[i][j] == '*')
                x = i, y = j;
        }
    }

    int query;
    string s;
    cin >> query >> s;

    int dir = 0, v = 0;

    for (int i = 0; i < query; i ++) {
        if (s[i] == 'L') {
            dir --;
            if (dir == -1) dir = 7;
        } else if (s[i] == 'R') {
            dir ++;
            if (dir == 8) dir = 0;
        } else if (s[i] == 'U') v ++;
        else if (s[i] == 'D') v = max(v - 1, 0);

        bool is = true;
        for (int step = 1; step <= v; step ++) {
            int xi = x + dirx[dir];
            int yi = y + diry[dir];
            if (dir & 1) {
                if (check(xi, yi) && G[xi][yi] != '#') {
                    if (G[xi][y] != '#' || G[x][yi] != '#') {
                        is = true;
                        x = xi, y = yi;
                    } else {
                        is = false;
                        v = 0;
                        break;
                    }
                } else {
                    is = false;
                    v = 0;
                    break;
                }
            } else {
                if (check(xi, yi) && G[xi][yi] != '#') {
                    is = true;
                    x = xi, y = yi;
                } else {
                    is = false;
                    v = 0;
                    break;
                }
            }
        }
        
        if (!is) cout << "Crash! ";
        cout << x << " " << y << '\n';
    }

    return 0;
}