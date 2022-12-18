//791.高精度加法
#include <bits/stdc++.h>
using namespace std;
vector<int> add(vector<int> &A, vector<int> &B) {
	vector<int> C;
	if (A.size() < B.size()) return add(B, A);
	int t = 0;
	for (int i = 0; i < A.size(); i ++) {
		t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if (t) C.push_back(1);
	return C;
}
int main() {
	string a, b;
	vector<int> A, B;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
	vector<int> C = add(A, B);
	for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
	return 0;
}
//782.高精度减法
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
bool cmp(vector<int> &A, vector<int> &B) {
	if (A.size() != B.size()) return A.size() > B.size();
	for (int i = A.size() - 1; i >= 0; i --)
		if (A[i] != B[i])
			return A[i] > B[i];
	return true;
}
vector<int> sub(vector<int> &A, vector<int> &B) {
	vector<int> C;
	for (int i = 0, t = 0; i < A.size(); i ++) {
		t = A[i] - t;
		if (i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		if (t < 0) t = 1;   //两数相差为负 向前一位借位 t --> 1
		else t = 0;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
int main() {
	string a, b;
	vector<int> A, B;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
	if (cmp(A, B)) {    //A >= B 输出第一种情况 即 A - B
		vector<int> C = sub(A, B);
		for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
	} else {
		vector<int> C = sub(B, A);
		printf("-");
		for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
	}
	return 0;
}
//793.高精度乘法
#include <bits/stdc++.h>
using namespace std;
vector<int> mul(vector<int> &A, int &B) {
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || t; i ++) {  //t 不为 0 且为最后一次输入时应 t --> C
		if (i < A.size()) t += A[i] * B;
		C.push_back(t % 10);
		t /= 10;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
int main() {
	string a;
	int B;
	vector<int> A;
	cin >> a >> B;
	for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
	vector<int> C = mul(A, B);
	for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
	return 0;
}
//794.高精度除法
#include <bits/stdc++.h>
using namespace std;
vector<int> mul(vector<int> &A, int &B, int &t) {
	vector<int> C;
	t = 0;
	for (int i = A.size() - 1; i >= 0; i --) {   //i 从最后一位 (原数最高位) 开始递减
		t = t * 10 + A[i];
		C.push_back(t / B);
		t %= B;
	}
	reverse(C.begin(), C.end()); //向量 C 中存入的为正序答案 为与其它三则运算保持一致性 故转置
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
int main() {
	string a;
	int B, t;
	vector<int> A;
	cin >> a >> B;
	for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
	vector<int> C = mul(A, B, t);
	for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
	printf("\n%d", t);
	return 0;
}
