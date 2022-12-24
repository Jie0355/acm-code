#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
	IOS
	int t;
	cin >> t;
	while (t --) {
		int s1, e1, s2, e2;
		bool vis[1450];
		memset(vis, false, sizeof vis);
		cin >> s1 >> e1 >> s2 >> e2;
		for (int i = s1; i <= e1; i ++) vis[i] = true;
		for (int i = s2; i <= e2; i ++) vis[i] = true;
		int n, is = 0;
		cin >> n;
		for (int i = 0; i < n; i ++) {
			int x;
			cin >> x;
			if (vis[x]) is = 1;
		}
		if (is) cout << "Y" << '\n';
		else cout << "N" << '\n';
	}
	return 0;
}