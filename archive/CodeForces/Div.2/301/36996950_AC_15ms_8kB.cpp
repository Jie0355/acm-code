//Title: A
//Date: 2022-07-06 13:01
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    IOS;
    int n, ans = 0;
    int x, y;
    char str1[1010], str2[1010];
    cin >> n;
    cin >> str1 >> str2;
    for (int i = 0; i < n; i ++) {
        x = abs(str1[i] - str2[i]);
        y = 10 - max(str1[i] - '0', str2[i] - '0') + min(str1[i] - '0', str2[i] - '0');
        ans += min(x, y);
    }
    cout << ans;
    return 0;
}