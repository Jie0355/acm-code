#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using LL = long long;
int main() {
	IOS
	int t;
	cin >> t;
	while (t --) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++)
				if ((i & 1) == (j & 1)) cout << -1 << " ";
				else cout << 1 << " ";
			cout << '\n';
		}
	}
	return 0;
}