#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m;
vector<pair<string, int>> vp;
int cal(int bit, int now) {
    for (int i = 0; i < n; i ++) {
        int x = vp[i].second;
        string op = vp[i].first;
        x = x >> bit & 1;
        if (op == "AND") now &= x;
        else if (op == "OR") now |= x;
        else now ^= x;
    }
    return now;
}
int main() {
    IOS
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        int x;
        string op;
        cin >> op >> x;
        vp.push_back({op, x});
    }
    int val = 0, ans = 0;
    for (int bit = 29; bit >= 0; bit --) {
        int i0 = cal(bit, 0);
        int i1 = cal(bit, 1);
        if (val + (1 << bit) <= m && i0 < i1)
            val += 1 << bit, ans += i1 << bit;
        else ans += i0 << bit;
    }
    cout << ans << '\n';
    return 0;
}