// A.M. Deviation
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int deviation(LL a, LL b, LL c) {
	int ans = a + c - 2 * b;
	if (ans % 3 == 0) return 0;
	else return 1;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n --) {
		LL a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (n != 0) printf("%d\n", deviation(a, b, c));
		else printf("%d", deviation(a, b, c));
	}
	return 0;
}
