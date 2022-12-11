#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if (i == 1 || x != v.back()) v.push_back(x);
    }
    int cnt = 0, isUp = 0, is = 1;
    for (int i = 1; i < v.size(); i ++) {
        if (v[i] > v[i - 1]) isUp= 1;
        if (v[i] < v[i - 1] && isUp) {is = 0; break;}
    }
    if (is) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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