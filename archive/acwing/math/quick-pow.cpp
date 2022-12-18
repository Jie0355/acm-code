//875.快速幂
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int quick_power(int a, int k, int p) {
	int res = 1;
	while (k) {
		if (k & 1) res = (LL)res * a % p;
		k >>= 1;
		a = (LL)a * a % p;
	}
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n --) {
		int a, k, p;
		scanf("%d %d %d", &a, &k, &p);
		printf("%d\n", quick_power(a, k, p));
	}
	return 0;
}
