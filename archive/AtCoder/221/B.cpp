#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e5 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

int main() {
    IOS;
    int i, cnt = 0;
    char str1[M], str2[M];
    cin >> str1 >> str2;
    int len = strlen(str1);
    for (i = 0; i < len; i ++) {
        if (str1[i] != str2[i]) {
            if (str1[i] == str2[i + 1] && str1[i + 1] == str2[i]) {
                if (cnt == 0) {
                    i ++;
                    cnt = 1;
                }
                else break;
            }
            else break;
        }
    }
    if (i == len) cout << "Yes";
    else cout << "No";
    return 0;
}
