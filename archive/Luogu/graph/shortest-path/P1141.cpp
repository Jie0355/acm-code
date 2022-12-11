#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int, int> PII;
int n, query, cnt;
char Gph[1010][1010];
int vis[1010][1010];
int tx[4] = {-1, 0, 1, 0}, ty[4] = {0, -1, 0, 1};
int Judge(int x1, int y1, int x2, int y2) {
    if (x2 > 0 && x2 <= n && y2 > 0 && y2 <= n)
        if (!vis[x2][y2] && Gph[x2][y2] != Gph[x1][y1])
            return 1;
    return 0;
}
void BFS(int xx, int yy) {
    queue<PII> q;
    cnt = 1;
    memset(vis, 0, sizeof(vis));
    q.push({xx, yy});
    vis[xx][yy] = 1;
    while (!q.empty()) {
        int nowx = q.front().first, nowy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int x = nowx + tx[i], y = nowy + ty[i];
            if (Judge(nowx, nowy, x, y) == 1) {
                q.push({x, y});
                vis[x][y] = 1;
                cnt ++;
            }
        }
    }
}
int main() {
    IOS;
    cin >> n >> query;
    for (int i = 1; i <= n; i ++) cin >> Gph[i];
    while (query --) {
        int x, y;
        cin >> x >> y;
        BFS(x, y);
        cout << cnt << endl;
    }
    return 0;
}