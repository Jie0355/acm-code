#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int M = 1e6 + 10;
constexpr int P = 1e9 + 7;

int fact[M];

void pre(int n) {
    fact[1] = 1;
    for (int i = 2; i <= n; i++) {
        fact[i] = (i64)fact[i - 1] * i % P;
    }
}

int quick_pow_i32(int a, int k, int p) {
    int res = 1 % p;
    for (; k; k >>= 1) {
        if (k & 1) res = (i64)res * a % p;
        a = (i64)a * a % p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    pre(n);

    cout << (fact[n] + P - quick_pow_i32(2, n - 1, P)) % P << '\n';

    return 0;
}