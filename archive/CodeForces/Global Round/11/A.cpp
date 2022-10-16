// Avoiding Zero
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 55;
int main() {
	int t, flag, a[MAX_N], N, sum, n;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &n);
		flag = sum = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (sum == 0) {
			printf("NO\n");
			continue;
		}
		if (sum > 0) {
			sort(a + 1, a + n + 1, greater<int>());
		} else {
			sort(a + 1, a + n + 1);
		}
		printf("YES\n");
		for (int i = 1; i <= n; ++i)
			printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}
