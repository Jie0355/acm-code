//842.排列数字
#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n;
int path[N];
bool vis[N];
void dfs(int u) {
	if (u == n) {
		for (int i = 0; i < n; i ++) cout << path[i] << ' ';
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			path[u] = i;
			vis[i] = true;
			dfs(u + 1);
			path[u] = 0;
			vis[i] = false; //回溯
		}
	}
}
int main() {
	cin >> n;
	dfs(0);
	return 0;
}
//843.N-皇后问题
//Solution 1
#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n;
char path[N][N];
bool row[N], dg[N * 2], udg[N * 2];
void dfs(int u) {
	if (u == n) {
		for (int i = 0; i < n; i ++) cout << path[i] << endl;
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i ++) {
		if (!row[i] && !dg[u + i] && !udg[n - u + i]) {
			path[u][i] = 'Q';
			row[i] = dg[u + i] = udg[n - u + i] = true;
			dfs(u + 1);
			//回溯
			path[u][i] = '.';
			row[i] = dg[u + i] = udg[n - u + i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			path[i][j] = '.';
	dfs(0);
	return 0;
}
//Solution 2
#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n;
char path[N][N];
bool row[N], col[N], dg[N * 2], udg[N * 2];
void dfs(int x, int y, int cnt) {
	if (cnt > n) return;
	if (y == n) y = 0, x ++;
	//已完成一种方案
	if (x == n) {
		//若该方案符合条件
		if (cnt == n) {
			for (int i = 0; i < n; i ++) cout << path[i] << endl;
			cout << endl;
		}
		return;
	}
	//点(X, Y)为无效选取点
	path[x][y] = '.';
	dfs(x, y + 1, cnt);
	//点(X, Y)为有效选取点
	if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
		path[x][y] = 'Q';
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
		dfs(x, y + 1, cnt + 1);
		//回溯
		path[x][y] = '.';
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
	}
}
int main() {
	cin >> n;
	dfs(0, 0, 0);
	return 0;
}
