#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;

priority_queue<int, vector<int>, less<int>> iq;
int ans[M], res[M];
i64 sum[M];
unordered_map<int, int> imp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, query;
    cin >> n >> query;

    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        iq.push(x);
    }

    for (int i = 1, x; i <= query; i ++) {
        cin >> x;
        ans[i] = x;
        res[i] = x;
    }

    sort(res + 1, res + query + 1);

    for (int i = 1; i <= query; i ++) {
        res[i] = res[i] - sum[i - 1];
        sum[i] = sum[i - 1] + res[i];
    }

    // for (int i = 1; i <= query; i ++) cout << res[i] << " ";
    // cout << '\n';

    for (int i = 1; i <= query; i ++) {
        int k = res[i];
        for (int i = 1; i <= k; i ++) {
            int x = iq.top();
            if (x == 1) break;
            iq.pop();
            x = __builtin_popcount(x);
            iq.push(x);
        }
        imp[k + sum[i - 1]] = iq.top();
    }

    for (int i = 1; i <= query; i ++) {
        cout << imp[ans[i]] << '\n';
    }

    return 0;
}