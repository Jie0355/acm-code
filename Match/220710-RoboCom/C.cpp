#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 2e4 + 10;
ll dice[1010] = {0};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll low = 0, up = 0;
    char str[M] = "+";
    scanf("%s", str + 1);
    //+d6+3d5+2-2d3+2d5
    for (int v = 1; v <= strlen(str) - 1; v ++) {
        if (str[v] == 'd') {
            int x = 0, y = 0, i = v - 1, j = v + 1;
            while (str[i] != '+' && str[i] != '-' && i > 0) {
                x += (str[i] - '0') * pow(10, v - i - 1);
                i --;
            }
            while (str[j] != '+' && str[j] != '-' && j <= strlen(str) - 1) {
                y = y * 10 + (str[j] - '0');
                j ++;
            }
            if (!x) x = 1;
            dice[y] += x;
            if (str[i] == '+') low += x, up += x * y;
            else low -= x * y, up -= x;
        }
        else if ((str[v - 1] == '-' || str[v - 1] == '+' || v == 1) && str[v] >= '1' && str[v] <= '9') {
            int x = 0, o;
            bool flag = true;
            for (o = v; str[o] != '-' && str[o] != '+' && o <= strlen(str) - 1; o ++) {
                if (str[o] == 'd') {
                    flag = false;
                    break;
                }
                x = x * 10 + (str[o] - '0');
            }
            if (flag) {
                if (v == 1 || str[v - 1] == '+') low += x, up += x;
                else low -= x, up -= x;
            }
            else v = o - 1;
        }
    }
    for (int i = 1; i <= 1000; i ++) {
        if (dice[i]) printf("%d %d\n", i, dice[i]);
    }
    printf("%lld %lld", low, up);
    return 0;
}