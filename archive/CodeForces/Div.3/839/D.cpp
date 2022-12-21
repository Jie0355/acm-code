#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int MAX = 1e9;
void solve() {
    int n, pre;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if (!i) pre = x;
        else {
            if (x > pre) {
                v.push_back({0, pre});
                if ((pre + x) % 2 == 0) v.push_back({(pre + x) / 2, (pre + x) / 2});
            } else if (x < pre) {
                v.push_back({x, MAX});
                if ((pre + x) % 2 == 0) v.push_back({(pre + x) / 2, (pre + x) / 2});
            }
        }
    }
    sort(v.begin(), v.end());
    vector<pair<int, int>> res;
    int l = v.front().first;
    int r = v.front().second;
    for (int i = 1; i < v.size(); i ++) {
        if (v[i].first > r) {
            res.push_back({l, r});
            l = v[i].first;
            r = v[i].second;
        } else {
            r = max(r, v[i].second);
        }
    }
    res.push_back({l, r});
    int x, pos = 0;
    for (x = 0; x <= MAX; x ++) {
        if (i >= res[pos].first && i<= res[pos].second) break;
        
    }
    if (x >= 0 && x <= MAX) cout << x << '\n';
    else cout << -1 << '\n';
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}