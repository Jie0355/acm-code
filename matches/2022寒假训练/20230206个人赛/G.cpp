#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e3 + 10;

int matrix[M][M];
int cntRow[M] = {0}, cntCol[M] = {0};
int adjRow[M] = {0}, adjCol[M] = {0};
int adjRowRes[M] = {0}, adjColRes[M] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1) {
                cntRow[i] ++;
                cntCol[j] ++;
            } else {
                adjRow[i] ^= matrix[i][j];
                adjCol[j] ^= matrix[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i ++) cin >> adjRowRes[i];

    for (int i = 1; i <= n; i ++) cin >> adjColRes[i];

    bool is = true;
    while (is) {
        is = false;
        for (int i = 1; i <= n; i ++) {
            // Row
            if (cntRow[i] == 1) {
                is = true;
                int pos;
                for (pos = 1; pos <= n; pos ++)
                    if (matrix[i][pos] == -1) break;
                matrix[i][pos] = adjRow[i] ^ adjRowRes[i];
                adjRow[i] ^= matrix[i][pos];
                adjCol[pos] ^= matrix[i][pos];
                cntRow[i] --, cntCol[pos] --;
            }
            // Col
            if (cntCol[i] == 1) {
                is = true;
                int pos;
                for (pos = 1; pos <= n; pos ++)
                    if (matrix[pos][i] == -1) break;
                matrix[pos][i] = adjCol[i] ^ adjColRes[i];
                adjRow[pos] ^= matrix[pos][i];
                adjCol[i] ^= matrix[pos][i];
                cntRow[pos] --, cntCol[i] --;
            }
        }

    }

    for (int i = 1; i <= n; i ++) {
        if (cntRow[i] || cntCol[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cout << matrix[i][j] << " \n"[j == n];

    return 0;
}