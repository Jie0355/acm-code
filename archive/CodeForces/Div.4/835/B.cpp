#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int n, x[30] = {0};
    string str;
    cin >> n >> str;
    for (int i = 0; i < str.size(); i ++)
        x[str[i] - 'a' + 1] ++;
    for (int i = 26; i >= 1; i --) {
        if (x[i]) {
            cout << i << '\n';
            break;
        }
    }
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}