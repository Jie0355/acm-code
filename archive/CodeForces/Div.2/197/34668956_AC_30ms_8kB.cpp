//C
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
    int n1 = 0, n2 = 0, n3 = 0;
    char str[110];
    cin >> str;
    for (int i = 0; str[i]; i ++) {
        if (str[i] == '1') n1 ++;
        else if (str[i] == '2') n2 ++;
        else if (str[i] == '3') n3 ++;
    }
    int k = 0;
    for (int i = 0; i < n1; i ++) {
        str[k++] = '1';
        str[k++] = '+';
    }
    for (int i = 0; i < n2; i ++) {
        str[k++] = '2';
        str[k++] = '+';
    }
    for (int i = 0; i < n3; i ++) {
        str[k++] = '3';
        str[k++] = '+';
    }
    for (int i = 0; i < (n1 + n2 + n3) * 2 - 1; i ++) cout << str[i];
    return 0;
}