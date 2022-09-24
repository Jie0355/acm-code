#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    IOS;
    int n, cnt = 1;
    string str;
    cin >> n >> str;
    for (int i = 1; i < str.size(); i ++)
        if (str[i] != str[i - 1]) cnt ++;
    cout << cnt;
    return 0;
}
