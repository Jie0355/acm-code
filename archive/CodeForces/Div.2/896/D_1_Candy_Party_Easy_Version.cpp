#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 lowbit(i64 x) {
    return x & (-x);
}

void solve() {
    int n;
    cin >> n;

    i64 sum = 0;
    vector<i64> v;
    for (int i = 0; i < n; i++) {
        i64 x;
        cin >> x;
        v.push_back(x);
        sum += x;
    }

    vector<i64> idxAdd(32, 0), idxDiff(32, 0);
    if (sum % n) cout << "No" << '\n';
    else {
        i64 div = sum / n;
        for (int i = 0; i < n; i++) {
            i64 dif = div - v[i];
            if (dif > 0) {
                vector<i64> t;
                while (dif) {
                    t.push_back(dif % 2);
                    dif /= 2;
                }
                int sizes = t.size();
                int idx;
                bool is = false;
                for (int j = 0; j < sizes; j++) {
                    if (!is && t[j]) {
                        is = true;
                        idx = j;
                    }
                    if (is && !t[j]) {
                        cout << "No" << '\n';
                        return;
                    }
                }
                idxAdd[sizes]++;
                idxDiff[idx]++;
            } else if (dif < 0) {
                dif = -dif;
                vector<i64> t;
                while (dif) {
                    t.push_back(dif % 2);
                    dif /= 2;
                }
                int sizes = t.size();
                int idx;
                bool is = false;
                for (int j = 0; j < sizes; j++) {
                    if (!is && t[j]) {
                        is = true;
                        idx = j;
                    }
                    if (is && !t[j]) {
                        cout << "No" << '\n';
                        return;
                    }
                }
                idxAdd[idx]++;
                idxDiff[sizes]++;
            }
        }
        for (int i = 0; i <= 31; i++) {
            if (idxAdd[i] != idxDiff[i]) {
                cout << "No" << '\n';
                return;
            }
        }
        cout << "Yes" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
