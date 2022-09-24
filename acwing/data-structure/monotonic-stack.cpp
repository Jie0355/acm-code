//830.单调栈
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int stk[N], top;
int main() {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> x;
		//新元素插入后 仍然保持栈严格单调递增
		while (top && stk[top] >= x) top --;
		if (!top) cout << -1 << ' ';
		else cout << stk[top] << ' ';
		stk[++ top] = x;
	}
	return 0;
}
