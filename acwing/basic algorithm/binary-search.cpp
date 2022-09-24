//789.数的范围
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
int a[MAX_N];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	while (m --) {
		int x, l = 0, r = n - 1;
		scanf("%d", &x);
		while (l < r) {
			int mid = l + r >> 1;
			if (a[mid] >= x) r = mid;
			else l = mid + 1;
		}
		if (a[l] != x) printf("-1 -1\n");
		else {
			printf("%d ", l);
			l = 0, r = n - 1;
			while (l < r) {
				int mid = l + r + 1 >> 1;
				if (a[mid] <= x) l = mid;
				else r = mid - 1;
			}
			printf("%d\n", l);
		}
	}
	return 0;
}
//790.数的三次方根
#include <bits/stdc++.h>
using namespace std;
int main() {
	double num;
	scanf("%lf", &num);
	double l = -10000, r = 10000;
	while (r - l > 1e-8) {
		double mid = (l + r) / 2;
		if (mid * mid * mid >= num) r = mid;
		else l = mid;
	}
	printf("%.6lf", l);
	return 0;
}
