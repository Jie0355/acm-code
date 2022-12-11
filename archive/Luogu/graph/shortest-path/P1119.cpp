#include <iostream>
#include <cstring>
using namespace std;
const int M = 210, INF = 0x3f3f3f3f;
int vex, acs, query, now = 1;
int Gph[M][M], vi[M];
void Floyd(int k) {
    for (int i = 1; i <= vex; i ++)
        for (int j = 1; j <= vex; j ++)
            Gph[i][j] = Gph[j][i] = min(Gph[i][j], Gph[i][k] + Gph[k][j]);
}
int main() {
    cin >> vex >> acs;
    for (int i = 1; i <= vex; i ++)
        for (int j = 1; j <= vex; j ++)
            if (i == j) Gph[i][j] = 0;
            else Gph[i][j] = INF;
    for (int i = 1; i <= vex; i ++) cin >> vi[i];
    while (acs --) {
        int a, b, w;
        cin >> a >> b >> w;
        a ++, b ++;
        Gph[a][b] = Gph[b][a] = w;
    }
    cin >> query;
    while (query --) {
        int x, y, t;
        cin >> x >> y >> t;
        x ++, y ++;
        while (vi[now] <= t && now <= vex) {
            Floyd(now);
            now ++;
        }
        if (vi[x] > t || vi[y] > t) cout << -1 << endl;
        else {
            if (Gph[x][y] == INF) cout << -1 << endl;
            else cout << Gph[x][y] << endl;
        }
    }
    return 0;
}