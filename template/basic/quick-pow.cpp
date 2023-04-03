// @description 快速幂(int)
int quick_pow(int a, int k, int p) {
    int res = 1 % p;
    for (; k; k >>= 1) {
        if (k & 1) res = (i64)res * a % p;
        a = (i64)a * a % p;
    }
    return res;
}