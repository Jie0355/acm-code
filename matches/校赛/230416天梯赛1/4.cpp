#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<int> s;
    for (int i = 0, m; i < n; i ++) {
        cin >> m;
        for (int j = 0, x; j < m; j ++) {
            cin >> x;
            if (m == 1) continue;
            s.insert(x);
        }
    }

    int query;
    vector<int> ans;
    cin >> query;
    for (int i = 0, x; i < query; i ++) {
        cin >> x;
        if (s.find(x) == s.end()) ans.push_back(x);
    }

    if (!ans.size()) {
        cout << "No one is handsome";
        return 0;
    }

    bool first = false;
    for (int i = 0; i < ans.size(); i ++) {
        int x = ans[i];
        bool is = true;
        for (int j = i - 1; j >= 0; j --) {
            if (ans[j] == x) {
                is = false;
                break;
            }
        }
        if (is) {
            if (!first) {
                printf("%05d", x);
                first = true;
            } else {
                printf(" %05d", x);
            }
        }
    }

    return 0;
}