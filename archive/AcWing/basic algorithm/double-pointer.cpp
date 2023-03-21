//799.最长连续不重复子序列
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], s[N];
int main() {
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i ++) scanf("%d", a + i);
	for (int i = 0, j = 0; i < n; i ++) {
		s[a[i]] ++;
		while (s[a[i]] > 1) {
			s[a[j]] --;
			j ++;
		}
		res = max(res, i - j + 1);
	}
	cout << res;
	return 0;
}
//800.数组元素的目标和
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
	int n, m, ans;
	int a[N], b[N];
	cin >> n >> m >> ans;
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i ++) scanf("%d", &b[i]);
	for (int i = 0, j = m - 1; i < n; i ++) {
		while (j >= 0 && a[i] + b[j] > ans) j --;
		if (a[i] + b[j] == ans) {
			printf("%d %d\n", i, j);
			break;
		}
	}
	return 0;
}
//2816.判断子序列
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
	int n, m;
	int a[N], b[N];
	cin >> n >> m;
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i ++) scanf("%d", &b[i]);
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] == b[j]) i ++;
		j ++;
	}
	if (i == n) printf("Yes");
	else printf("No");
	return 0;
}
