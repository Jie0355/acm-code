//787.归并排序
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
int q[MAX_N], temp[MAX_N], n;
void merge_sort(int q[], int l, int r) {
	if (l >= r) return;
	int mid = l + r >> 1;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (q[i] <= q[j]) temp[k ++] = q[i ++];
		else temp[k ++] = q[j ++];
	}
	while (i <= mid) temp[k ++] = q[i ++];
	while (j <= r) temp[k ++] = q[j ++];
	for (i = l, j = 0; i <= r; i ++, j ++) q[i] = temp[j];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
	merge_sort(q, 0, n - 1);
	for (int i = 0; i < n; i ++) printf("%d ", q[i]);
	return 0;
}
//788.逆序对的数量
/*
存在正整数 i, j 使得 1 ≤ i < j ≤ n 而且 A[i] > A[j]
则 <A[i], A[j]> 这个有序对称为 A 的一个逆序对
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX_N = 1e5 + 10;
int q[MAX_N], temp[MAX_N], n;
LL merge_sort(int l, int r) {
	if (l >= r) return 0;
	int mid = l + r >> 1;
	LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r) {
		if (q[i] <= q[j]) temp[k ++] = q[i ++];
		else {
			temp[k ++] = q[j ++];
			res += mid - i + 1;
		}
	}
	while (i <= mid) temp[k ++] = q[i ++];
	while (j <= r) temp[k ++] = q[j ++];
	for (int i = l, j = 0; i <= r; i ++, j ++) q[i] = temp[j];
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
	printf("%lld", merge_sort(0, n - 1));
	return 0;
}
