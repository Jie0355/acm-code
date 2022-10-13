#include <iostream>
using namespace std;
typedef long long LL;
const int M = 1e5 + 10, INF = 0x3f3f3f3f;
const double eps = 1e-6;
int main() {
	int n, L;
	LL arr[M];
	cin >> n >> L;
	double l = INF, r = 0;
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		l = min(l, (double)arr[i]);
		r = max(r, (double)arr[i]);
	}
	double sum[M] = {0};
	while (r - l > eps) {
		double mid = (l + r) / 2.0;
		for (int i = 0; i < n; i ++)
			sum[i + 1] = sum[i] + (double)arr[i] - mid;
		double sumMax = - INF, preMin = 0;
		for (int i = L; i <= n; i ++) {
			sumMax = max(sumMax, sum[i] - preMin);
			preMin = min(preMin, sum[i - L + 1]);
		}
		if (sumMax >= 0) l = mid;
		else r = mid;
	}
	cout << l * 1000 << '\n';
	return 0;
}
