#include <iostream>
using namespace std;
const int M = 510, INF = 0x3f3f3f3f;
int v, e, query;
int Gph[M][M];
void Floyd() {
    for (int k = 1; k <= v; k ++)
        for (int i = 1; i <= v; i ++)
            for (int j = 1; j <= v; j ++)
                Gph[i][j] = min(Gph[i][j], Gph[i][k] + Gph[k][j]);
}
int main() {
    cin >> v >> e;
    for (int i = 1; i <= v; i ++)
        for (int j = 1; j <= v; j ++)
            if (i == j) Gph[i][j] = 0;
            else Gph[i][j] = INF;
    while (e --) {
        int a, b, w;
        cin >> a >> b >> w;
        Gph[a][b] = min(w, Gph[a][b]);
    }
    Floyd();
    cin >> query;
    while (query --) {
        int x, y;
        cin >> x >> y;
        int dist = Gph[x][y];
        if (dist > INF / 2) printf("%d->%d:-1\n", x, y);
        else printf("%d->%d:%d\n", x, y, dist);
    }
    return 0;
}