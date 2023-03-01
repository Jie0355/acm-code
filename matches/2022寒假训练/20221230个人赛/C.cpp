#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int f[15] = {0};
    for (int i = 1; i <= 9; i ++) cin >> f[i];
    
    bool is = false;
    for (int i = 0; i < s.size(); i ++) {
        if (f[s[i] - '0'] > (s[i] - '0') && !is) {
            is = true;
            int j;
            for (j = i; j < s.size(); j ++) {
                if (f[s[j] - '0'] < (s[j] - '0')) {
                    i = j;
                    break;
                }
                cout << f[s[j] - '0'];
            }
            if (j == s.size()) return 0;
        }
        cout << s[i];
    }

    return 0;
}