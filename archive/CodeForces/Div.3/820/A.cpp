#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
	IOS
	int t;
	cin >> t;
	while (t --) {
		int a, b, c;
		cin >> a >> b >> c;
		int t1 = a, t2 = abs(b - c) + c;
		if (t1 < t2) cout << 1 << '\n';
		else if (t1 > t2) cout << 2 << '\n';
		else cout << 3 << '\n';
	}
	return 0;
}
