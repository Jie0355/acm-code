#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
// @description 快速幂变式
LL bigINT_mul(LL a, LL b, LL p) {
    LL res = 0;
    for (; b; b >>= 1) {
        if (b & 1) res = (res + a) % p;
        a = a * 2 % p;
    }
    return res;
}
int main() {
    IOS
    LL a, b, p;
    cin >> a >> b >> p;
    cout << bigINT_mul(a, b, p) << '\n';
    return 0;
}