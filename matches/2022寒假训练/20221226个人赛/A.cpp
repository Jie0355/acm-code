#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    string s;
    cin >> s;
    int len_a = 0, len_ab = 0, len_aba = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'a') len_a ++, len_aba ++;
        else len_ab ++;
        len_a = max(len_a, len_ab);
        len_ab = max(len_aba, len_ab);
    }
    cout << len_a << '\n';
    return 0;
}