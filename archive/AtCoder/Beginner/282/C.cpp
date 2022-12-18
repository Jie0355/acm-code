#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int n;
    string s;
    cin >> n >> s;
    bool is = false;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '"') {
            is = !is;
            cout << '"';
            continue;
        }
        if (!is && s[i] == ',') cout << '.';
        else cout << s[i];
    }
    return 0;
}