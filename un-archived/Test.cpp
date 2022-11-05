#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
const int M = 1e5 + 10;
int main() {
	IOS
	int n;
	int arr[M], dp[M] = {0};
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> arr[i];
	for (int i = 1; i <= n; i ++) {	
		bool flag = true;
		if (i > 1 && arr[i - 1] < arr[i]) flag = false;
		if (i < n && arr[i + 1] < arr[i]) flag = false;
		if (flag) dp[i] = 1;
	}
	LL ans = 0;
	for (int i = 2; i <= n; i ++)
		if (arr[i] > arr[i - 1])
			dp[i] = max(dp[i], dp[i - 1] + 1);
	for (int i = n - 1; i > 0; i --)
		if (arr[i] > arr[i + 1])
			dp[i] = max(dp[i], dp[i + 1] + 1);
	for (int i = 1; i <= n; i ++) ans += dp[i];
	cout << ans << '\n';
	return 0;
}