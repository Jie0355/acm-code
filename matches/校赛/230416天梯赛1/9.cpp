#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e4 + 10;

int cnt[M] = {0};

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first > b.first;
    else if (cnt[a.second] != cnt[b.second]) return cnt[a.second] > cnt[b.second];
    else return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> imp;
    for (int i = 1; i <= n; i ++) {
        int m;
        cin >> m;
        int sum = 0;
        for (int j = 0; j < m; j ++) {
            int no, num;
            cin >> no >> num;
            imp[no] += num;
            cnt[no] ++;
            sum += num;
        }
        imp[i] -= sum;
    }

    int k = 0;
    pair<int, int> ans[M];
    for (auto xi : imp) {
        ans[k ++] = {xi.second, xi.first};
    }

    sort(ans, ans + n, cmp);

    for (int i = 0; i < n; i ++) {
        int no = ans[i].second;
        double num = 1.0 * ans[i].first / 100;
        printf("%d %.2lf\n", no, num);
    }

    return 0;
}