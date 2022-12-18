#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == '0') cnt0 ++;
        else cnt1 ++;
    }
    int l = pow(2, cnt1);
    int r = pow(2, n) - pow(2, cnt0) + 1;
    for (int i = l; i <= r; i ++) cout << i << " ";
    cout << '\n';
}
int main() {
    IOS
    solve();
    return 0;
}