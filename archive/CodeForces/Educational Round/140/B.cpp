#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
void solve() {
    int n, x;
    cin >> n;
    vector<int> v;
    cin >> x;
    for (int i = 2; i <= n; i ++) {
        int vt;
        cin >> vt;
        if (vt > x) v.push_back(vt);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i ++) {
        if (((LL)x + v[i]) % 2 == 0) x = ((LL)x + v[i]) / 2;
        else x = ((LL)x + v[i]) / 2 + 1;
    }
    cout << x << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}