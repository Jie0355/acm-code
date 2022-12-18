//829.模拟队列
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int q[N], hh, tt;
int main() {
	int t;
	cin >> t;
	while (t --) {
		int x;
		string op;
		cin >> op;
		if (op == "push") {
			cin >> x;
			q[tt ++] = x;
		} else if (op == "pop") hh ++;
		else if (op == "empty") {
			if (hh < tt) cout << "NO" << endl;
			else cout << "YES" << endl;
		} else cout << q[hh] << endl;
	}
	return 0;
}
