#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
int main() {
	IOS
	int t;
	cin >> t;
	while (t --) {
		LL l, r, ans = 0;
		cin >> l >> r;
		for (LL i = l; i <= l + (r - l) % 9; i ++)
			ans = (ans + (i % 9)) % 9;
		cout << ans << '\n';
	}
	return 0;
}