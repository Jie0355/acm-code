//828.模拟栈
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int stk[N], tt = 0;
int main() {
	int t;
	cin >> t;
	while (t --) {
		int x;
		string op;
		cin >> op;
		if (op == "push") {
			cin >> x;
			stk[tt ++] = x;
		} else if (op == "pop") tt --;
		else if (op == "empty") {
			if (tt > 0) cout << "NO" << endl;
			else cout << "YES" << endl;
		} else cout << stk[tt - 1] << endl;
	}
	return 0;
}
//3302.表达式求值
#include <bits/stdc++.h>
using namespace std;
stack<int> num;
stack<char> op;
void eval() {
	auto b = num.top();
	num.pop();
	auto a = num.top();
	num.pop();
	auto c = op.top();
	op.pop();
	int x;
	if (c == '+') x = a + b;
	else if (c == '-') x = a - b;
	else if (c == '*') x = a * b;
	else x = a / b;
	num.push(x);
}
int main() {
	string str;
	unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
	cin >> str;
	for (int i = 0; i < str.size(); i ++) {
		auto c = str[i];
		if (isdigit(c)) {
			int x = 0, j = i;
			while (j < str.size() && isdigit(str[j]))
				x = x * 10 + str[j ++] - '0';
			i = j - 1;
			num.push(x);
		} else if (c == '(') op.push(c);
		else if (c == ')') {
			while (op.top() != '(') eval();
			op.pop();
		} else {
			while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c]) eval();
			op.push(c);
		}
	}
	while (op.size()) eval();
	cout << num.top();
	return 0;
}
