#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, s;
    cin >> n >> k >> s;

    vector<int> v(M);
    for (int i = 0; i < s; i ++) {
        int ni, ki;
        cin >> ni >> ki;
        v[ni] += ki;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (v[i] < k) cnt ++;
    }

    cout << cnt << '\n';

    return 0;
}