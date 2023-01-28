#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 110;

int n, m, G[M][M];
int stx, sty, edx, edy;
int dirx[4] = {-1, 1, 0, 0}, diry[4] = {0, 0, -1, 1};
bool vis[M][M], is;
vector<vector<int>> VV(11);

bool check(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y]) return true;
	return false; 
}

void DFS(int x, int y, int scheme) {
	if (x == edx && y == edy) {
		is = true;
		return;
	}
	for (int i = 0; i < 4; i ++) {
		int xi = x + dirx[i];
		int yi = y + diry[i];
		if (check(xi, yi) && (1 << G[xi][yi] - 1) & scheme) {
			vis[xi][yi] = true;
			DFS(xi, yi, scheme);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i < (1 << 10); i ++)
		VV[__builtin_popcount(i)].push_back(i);

	cin >> n >> m;
	cin >> stx >> sty >> edx >> edy;

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			cin >> G[i][j];

	for (int i = 1; i <= 10; i ++) {
		for (auto xi : VV[i]) {
			if ((1 << G[stx][sty] - 1) & xi) {
				is = false;
				memset(vis, false, sizeof vis);
				DFS(stx, sty, xi);
			}
			if (is) {
				cout << i << '\n';
				return 0;
			}
		}
	}
}