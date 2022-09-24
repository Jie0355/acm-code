//C
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e5 + 7;
const int MOD = 1e9 + 7;

int main() {
    IOS;
    int lim = 0;
    char str[505];
    cin >> str;
    for (int i = 0; str[i]; i ++) {
        if (i == 0 && str[i] != 'a') {
            cout << "NO";
            return 0;
        }
        if (str[i] - 'a' <= lim) {
            continue;
        }
        else {
            if (str[i] - 'a' == lim + 1) lim ++;
            else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}