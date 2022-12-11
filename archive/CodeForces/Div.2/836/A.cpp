#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    string str;
    cin >> str;
    cout << str;
    reverse(str.begin(), str.end());
    cout << str << '\n';
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