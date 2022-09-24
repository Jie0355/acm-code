//Title: E - AFterMATCH
//Date: 2022-07-09 15:00
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int M = 110;
int Gph[M][M] = {0}, FullGph[M];
int main() {
    IOS;
    for (int i = 3; i <= 100; i ++) FullGph[i] = i * (i - 1) * (i - 2) / 6;
    int k, low = 100;
    cin >> k;
    while (k < FullGph[low]) low --;
    for (int i = 1; i <= low; i ++)
        for (int j = 1; j <= low; j ++)
            if (i != j) Gph[i][j] = Gph[j][i] = 1;
    k -= FullGph[low];
    for (int i = low - 2; i >= 1; i --) {
        while (k >= i * (i + 1) / 2) {
            k -= i * (i + 1) / 2;
            low ++;
            for (int o = 1; o <= i + 1; o ++)
                Gph[low][o] = Gph[o][low] = 1;
        }
    }
    cout << low << endl;
    for (int i = 1; i <= low; i ++) {
        for (int j = 1; j <= low; j ++)
            cout << Gph[i][j];
        cout << endl;
    }
    return 0;
}