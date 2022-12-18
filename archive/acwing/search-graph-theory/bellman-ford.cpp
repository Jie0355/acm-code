//853.有边数限制的最短路
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e4 + 10, M = 510, INF = 0x3f3f3f3f;
struct graph {
	int a, b, w;
} Gph[N];
int v, e, k, st = 1;
int dist[M], backup[M];
void Bellman_Ford(int u) {
	memset(dist, INF, sizeof dist);
	dist[u] = 0;
	for (int i = 0; i < k; i ++) {
		memcpy(backup, dist, sizeof dist);
		for (int j = 0; j < e; j ++) {
			int a = Gph[j].a, b = Gph[j].b, w = Gph[j].w;
			dist[b] = min(dist[b], backup[a] + w);
		}
	}
}
int main() {
	cin >> v >> e >> k;
	for (int i = 0; i < e; i ++) {
		int a, b, w;
		cin >> a >> b >> w;
		Gph[i] = {a, b, w};
	}
	Bellman_Ford(st);
	if (dist[v] > INF / 2) cout << "impossible";
	else cout << dist[v];
	return 0;
}
