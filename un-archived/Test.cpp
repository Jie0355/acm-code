#include <iostream>
#include <vector>
using namespace std;
#define x first
#define y second
const int M = 110, INF = 0x3f3f3f3f;
int main() {
	int n, row, col;
	int dp[M][M] = {0};
	vector<pair<int, int>> v;
	cin >> n >> row;
	v.push_back({0, 0});
	for (int i = 0; i < n; i ++) {
		cin >> col;
		v.push_back({row, col});
		row = col;
	}
	for (int u = 2; u <= n; u ++) {
		for (int i = 1; i <= n - u + 1; i ++) {
			int j = i + u - 1;
			dp[i][j] = INF;
			for (int k = i; k < j; k ++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i].x * v[k + 1].x * v[j].y);
		}
	}
	cout << dp[1][n] << '\n';
	return 0;
}