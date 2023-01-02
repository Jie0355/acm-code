#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
// @description 快速幂(int)
int quick_pow(int a, int k, int p) {
    int res = 1 % p;
    for (; k; k >>= 1) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
    }
    return res;
}
int main() {
    IOS
    int a, k, p;
    cin >> a >> k >> p;
    int ans = quick_pow(a, k, p);
    printf("%d^%d mod %d=%d", a, k, p, ans);
    return 0;
}