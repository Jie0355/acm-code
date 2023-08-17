#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> v;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        v.push_back(x);
    }
    
    vector<int> xorv(v);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    cout << t << '\n';
    
    while (t--)
        solve();
    
    return 0;
}
