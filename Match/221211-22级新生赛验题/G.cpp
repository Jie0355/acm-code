#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
int main() {
	IOS
	int p;
	LL n, m;
	cin >> n >> m >> p;
	int dpTen[20];
	dpTen[1] = 10 % p;
	for (int i = 2; i <= 18; i ++)
		dpTen[i] = ((dpTen[i - 1] % p) * dpTen[1]) % p;
	LL t = n, ten = 0;
	while (t) {
		t /= 10;
		ten ++;
	}
	// cout << ten << " " << dpTen[ten] << '\n';
	LL fst = n % p, pre = fst, ans = fst, dp;
	for (int i = 2; i <= min(m, 1LL * p); i ++) {
		dp = ((pre * dpTen[ten]) % p + fst) % p;
		pre = dp;
		ans = max(1LL * ans, dp);
	}
	// for (int i = 1; i <= p; i ++) cout << dp[i] << " ";
	cout << ans << '\n';
	return 0;
}