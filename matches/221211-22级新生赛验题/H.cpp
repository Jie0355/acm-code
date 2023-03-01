#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e4 + 10;
int main() {
	IOS
	int n, m, q;
	cin >> n >> m >> q;
	double poss = 1.0 * m / 100;
	double ans[M] = {0};
	ans[1] = 1;
	while (q --) {
		int x, y;
		cin >> x >> y;
		double tX = ans[x], tY = ans[y];
		ans[x] = tX + (1 - tX) * tY * poss;
		ans[y] = tY + (1 - tY) * tX * poss;
	}
	for (int i = 1; i <= n; i ++) printf("%.8lf ", ans[i]);
	return 0;
}