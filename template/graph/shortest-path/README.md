# 最短路算法 · Shortest-Path

对于 $n$ 个点 $m$ 条边的图，有以下求最短路的算法。

- 单源最短路
	- 所有边权都是正值
		- 朴素Dijkstra `O(n^2)`
		- 堆优化Dijkstra `O(mlogn)`
	- 存在负权边
		- Bellman-Ford `O(nm)`
		- SPFA 一般`O(m)` | 最坏 `O(nm)`
- 多源汇最短路
	- Floyd `O(n^3)`