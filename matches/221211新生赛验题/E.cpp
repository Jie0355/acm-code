#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e5 + 10;
int main() {
	IOS
	int n, m, arr[M], des[M] = {0};
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> arr[i];
	while (m --) {
		int x, y;
		cin >> x >> y;
		des[x] = y;
	}
	for (int i = 0; i < n; i ++) {
		int t = arr[i];
		while (des[t]) t = des[t];
		cout << t << " ";
	}
	return 0;
}