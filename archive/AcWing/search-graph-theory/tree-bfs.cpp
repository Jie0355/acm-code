//847.图中点的层次
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int head[N], e[N], ne[N], idx = 0; //数组模拟邻接表
void add(int a, int b) {
	e[idx] = b;
	ne[idx] = head[a];
	head[a] = idx ++;
}
int BFS() {
	//数组模拟队列
	int hhead = 0, tail = 0;
	int queue[N], dis[N];
	memset(dis, -1, sizeof(dis)); //步长初始化为-1
	queue[tail ++] = 1;
	dis[1] = 0;
	while (hhead != tail) { //队列不为空
		int tmp = queue[hhead ++]; //取出队头
		for (int i = head[tmp]; i != -1; i = ne[i]) {
			if (dis[e[i]] == -1) { //该点可走
				dis[e[i]] = dis[tmp] + 1; //步长+1
				queue[tail ++] = e[i]; //入队
			}
		}
	}
	return dis[n];
}
int main() {
	cin >> n >> m;
	memset(head, -1, sizeof(head)); //初始化头节点数组为-1
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		add(a, b); //有向图
	}
	cout << BFS() << endl;
	return 0;
}
