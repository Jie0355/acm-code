//826.双链表
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int e[N], l[N], r[N], idx;
void Init() {
	l[1] = 0;
	r[0] = 1;
	idx = 2;
}
void Add(int x, int k) {
	e[idx] = x;
	l[idx] = k, r[idx] = r[k];
	l[r[k]] = idx, r[k] = idx;
	idx ++;
}
void Remove(int k) {
	l[r[k]] = l[k];
	r[l[k]] = r[k];
}
int main() {
	Init();
	int t;
	cin >> t;
	while (t --) {
		string op;
		int x, k;
		cin >> op;
		if (op == "L") {
			cin >> x;
			Add(x, 0);
		} else if (op == "R") {
			cin >> x;
			Add(x, l[1]);
		} else if (op == "D") {
			cin >> k;
			Remove(k + 1);
		} else if (op == "IL") {
			cin >> k >> x;
			Add(x, l[k + 1]);
		} else {
			cin >> k >> x;
			Add(x, k + 1);
		}
	}
	for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
	return 0;
}
