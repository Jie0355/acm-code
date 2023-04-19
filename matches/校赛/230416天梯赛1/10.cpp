#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 110;

int n, m, query;
int st, ed;
int Gph[M][M] = {0};
bool isFri, first, vis[M];

void DFS(int u, bool fri) {
    if (u == ed) {
        if (fri && first) {
            isFri = true;
            first = false;
        }
        return;
    }
    for (int i = 1; i <= n; i ++) {
        if (!vis[i] && Gph[u][i]) {
            if (Gph[u][i] == -1) fri = false;
            vis[i] = true;
            DFS(i, fri);
            if (Gph[u][i] == -1) fri = true;
            vis[i] = false;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> query;

    for (int i = 0; i < m; i ++) {
        int x, y, rel;
        cin >> x >> y >> rel;
        Gph[x][y] = Gph[y][x] = rel;
    }

    for (int i = 0; i < query; i ++) {
        cin >> st >> ed;
        isFri = true, first = true;
        vis[st] = true;
        DFS(st, isFri);
        if (first) isFri = false;
        if (isFri) {
            if (Gph[st][ed] != -1) cout << "No problem" << '\n';
            else cout << "OK but..." << '\n';
        } else {
            if (Gph[st][ed] != -1) cout << "OK" << '\n';
            else cout << "No way" << '\n';
        }
    }

    return 0;
}