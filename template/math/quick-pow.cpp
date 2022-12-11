#include <iostream>
using namespace std;
typedef long long LL;
int quick_pow(int a, int k, int p) {
	int res = 1;
	while (k) {
		if (k & 1) res = (LL) res * a % p;
		k >>= 1;
		a = (LL) a * a % p;
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	while (n --) {
		int a, k, p;
		cin >> a >> k >> p;
		cout << quick_pow(a, k, p) << '\n';
	}
	return 0;
}