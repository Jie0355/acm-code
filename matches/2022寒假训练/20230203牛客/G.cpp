#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> pos, neg;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        if (x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<int>());

    int ans = 0;
    while (k --) {
        int res1 = -1, res2 = -1;
        if (pos.size() >= 2) res1 = pos[pos.size() - 1] * pos[pos.size() - 2];   
        if (neg.size() >= 2) res2 = neg[neg.size() - 1] * neg[neg.size() - 2];
        if (pos.size() < 2 && neg.size() < 2) {
            ans += pos.back() * neg.back();
            break;
        }
        if (res1 > res2) {
            ans += res1;
            pos.pop_back();
            pos.pop_back();
        } else {
            ans += res2;
            neg.pop_back();
            neg.pop_back();
        }
    }

    cout << ans << '\n';

    return 0;
}