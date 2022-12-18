// @description 快速幂(int)
using LL = long long;
int quick_pow(int a, int k, int p) {
    int res = 1 % p;
    for (; k; k >>= 1) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
    }
    return res;
}