#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    IOS;
    int ans = 0, l = 0;
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.size() > str2.size()) swap(str1, str2);
    for (int i = 0; i < str1.size(); i ++) {
        int flag1 = 1, flag2 = 1;
        char tmp[100010];
        tmp[l ++] = str1[i];
        if (str1.size() % l != 0 || str2.size() % l != 0) continue;
        for (int j = i + 1; j < str1.size();) {
            for (int k = 0; k < l; k ++) {
                if (str1[j ++] != tmp[k]) {flag1 = 0; break; }
            }
            if (!flag1) break;
        }
        if (flag1) {
            for (int j = 0; j < str2.size();) {
                for (int k = 0; k < l; k ++) {
                    if (str2[j ++] != tmp[k]) {flag2 = 0; break; }
                }
                if (!flag2) break;
            }
            if (flag2) ans ++;
        }
    }
    cout << ans;
    return 0;
}