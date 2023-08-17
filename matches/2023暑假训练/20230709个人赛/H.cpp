#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 5e2 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 arr[M];
    for (int i = 1; i <= 450; i ++) {
        arr[i] = i * (i + 1) / 2;
    }

    int k;
    cin >> k;

    if (!k) cout << "a" << '\n';

    string s;
    for (int i = 1; i <= 26; i ++) {
        int pos = upper_bound(arr + 1, arr + 450 + 1, k) - arr - 1;
        if (!pos) break;
        // cout << pos + 1 << " " << char('a' + i - 1) << " " << k << " " << arr[pos] << '\n';
        for (int j = 0; j <= pos; j ++) s.push_back('a' + i - 1);
        k -= arr[pos];
    }
    cout << s << '\n';

    return 0;
}