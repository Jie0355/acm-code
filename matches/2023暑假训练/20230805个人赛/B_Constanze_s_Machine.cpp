#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;
const int P = 1e9 + 7;

i64 ret[M];

void fib(int n) {
    ret[2] = 2, ret[3] = 3;
    for (int i = 4; i <= n; i ++) {
        ret[i] = ret[i - 1] + ret[i - 2];
        ret[i] %= P;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    if (find(s.begin(), s.end(), 'm') != s.end() || find(s.begin(), s.end(), 'w') != s.end()) {
        cout << 0 << '\n';
        return 0;
    }

    int n = s.size();

    fib(n);

    i64 ans = 1;
    for (int i = 1; i < n; i ++) {
        int idx = i;
        while (s[idx] == s[idx - 1] && (s[idx] == 'u' || s[idx] == 'n') && idx < n) idx ++;
        int sizes = idx - i + 1;
        if (sizes >= 2) {
            ans = ans * ret[sizes] % P;
            // cout << sizes << " ";
        }
        i = idx;
    }

    cout << ans << '\n';

    return 0;
}