#include <iostream>
#include <cstring>
using namespace std;
const int M = 210, INF = 0x3f3f3f3f;
int n;
int Gph[M][M];
void Floyd() {
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                Gph[i][j] = min(Gph[i][j], Gph[i][k] + Gph[k][j]);
}
int main() {
    memset(Gph, INF, sizeof Gph);
    cin >> n;
    for (int i = 1; i <= n -1; i ++)
        for (int j = i + 1; j <= n; j ++)
            cin >> Gph[i][j];
    Floyd();
    cout << Gph[1][n];
    return 0;
}