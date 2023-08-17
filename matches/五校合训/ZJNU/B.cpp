#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e3 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    i64 arr[M];
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
    }

    int pos;
    i64 cnt = 0;
    for (int i = 1; i <= n; i ++) {
        vector<int> pre, suf;
        for (int j = 1; j < i; j ++) {
            if (arr[j] < arr[i]) pre.push_back(arr[j]);
        }
        for (int j = i + 1; j <= n; j ++) {
            if (arr[j] < arr[i]) suf.push_back(arr[j]);
        }
        sort(pre.begin(), pre.end());
        sort(suf.begin(), suf.end());
        for (int j = 0; j < pre.size(); j ++) {
            int x = arr[i] - pre[j];
            pos = lower_bound(suf.begin(), suf.end(), x) - suf.begin();
            // cout << x << " " << pos << '\n';
            if (suf[pos] == x) cnt += pos + 1;
            else cnt += pos;
        }
    }

    cout << cnt << '\n';

    return 0;
}