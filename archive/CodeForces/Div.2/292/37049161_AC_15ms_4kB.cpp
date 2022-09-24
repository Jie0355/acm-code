//Title: B
//Date: 2022-07-08 14:31
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    IOS;
    int n, num[15] = {0};
    char s[20];
    cin >> n >> s;
    for (int i = 0; s[i]; i ++) {
        if (s[i] == '4') {num[2] += 2; num[3] ++; }
        else if (s[i] == '6') {num[3] ++; num[5] ++; }
        else if (s[i] == '8') {num[2] += 3; num[7] ++; }
        else if (s[i] == '9') {num[2] ++; num[3] += 2; num[7] ++;}
        else num[s[i] - '0'] ++;
    }
    for (int i = 9; i >= 2; i --)
        while (num[i]) {
            num[i] --;
            cout << i;
        }
    return 0;
}