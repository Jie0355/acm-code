//846.树的重心
#include <bits/stdc++.h>
using namespace std;
//以有向图的格式存储无向图 所以每个节点至多对应2N-2条边
const int N = 1e5 + 10, M = 2 * N;
int n, ans = N;
int head[N], e[M], ne[M], idx = 0; //数组模拟邻接表
bool vis[N];
void add(int a, int b) {
	e[idx] = b;
	ne[idx] = head[a];
	head[a] = idx ++;
}
int DFS(int u) {
	vis[u] = true; //标记访问过u节点
	int sum = 0, LowerPart = 0;
	for (int i = head[u]; i != -1; i = ne[i]) {
		if (vis[e[i]]) continue; //该节点已被访问过
		int size = DFS(e[i]); //某一条路径的长度
		LowerPart = max(LowerPart, size); //最大连通子图的长度
		sum += size; //以e[i]为根的树的结点数
	}
	LowerPart = max(LowerPart, n - sum - 1); //以u节点为重心的最大连通子图的节点数
	ans = min(ans, LowerPart); //遍历过的假设重心中最小的最大连通子图节点数
	return sum + 1;
}
int main() {
	cin >> n;
	memset(head, -1, sizeof(head)); //初始化头节点数组为-1
	for (int i = 0; i < n - 1; i ++) {
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a); //无向图
	}
	DFS(1);
	cout << ans;
	return 0;
}
