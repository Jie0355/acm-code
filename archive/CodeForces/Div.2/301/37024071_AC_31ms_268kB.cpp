//Title: G - AfterMATCH
//Date: 2022-07-07 14:02
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> PII;
int n, m;
int startx, starty, endx, endy;
char Gph[510][510];
bool BFS() {
    queue<PII> q;
    int tx[4] = {-1, 0, 1, 0}, ty[4] = {0, -1, 0, 1};
    q.push({startx, starty});
    while (!q.empty()) {
        int xx = q.front().first, yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int x = xx + tx[i], y = yy + ty[i];
            if (x > 0 && x <= n && y > 0 && y <= m && Gph[x][y] == '.') {
                Gph[x][y] = 'X';
                q.push({x, y});
            }
            else if (x == endx && y == endy && Gph[x][y] == 'X') return true;
        }
    }
    return false;
}
int main() {
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> Gph[i][j];
    cin >> startx >> starty;
    cin >> endx >> endy;
    bool ans = BFS();
    if (ans == true) cout << "YES";
    else cout << "NO";
    return 0;
}