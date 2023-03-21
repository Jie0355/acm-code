//826.单链表
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int e[N], ne[N], head, idx;
void Init() {
	head = -1;
	idx = 0;
}
void AddToHead(int x) {
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx ++;
}
void Add(int x, int k) {
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx ++;
}
void Remove(int k) {
	ne[k] = ne[ne[k]];
}
int main() {
	Init();
	int t, x, k;
	char op;
	cin >> n;
	while (n --) {
		cin >> op;
		if (op == 'H') {
			cin >> x;
			AddToHead(x);
		} else if (op == 'D') {
			cin >> k;
			if (!k) head = ne[head];
			else Remove(k - 1);
		} else {
			cin >> k >> x;
			Add(x, k - 1);
		}
	}
	for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
	return 0;
}
