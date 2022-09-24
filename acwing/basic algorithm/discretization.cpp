//802.离散化
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 3e5 + 10;
int a[N] = {0}, s[N] = {0};
vector<int> alls;   //存储即将使用的数轴点
vector<PII> add, query;
//返回数轴上的点{x}在序列中的位置
int find(int x) {
	int l = 0, r = alls.size() - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		alls.push_back(x);
	}
	for (int i = 0; i < m; i ++) {
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});
		alls.push_back(l);
		alls.push_back(r);
	}
	//去重
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	//离散化
	for (auto item : add) {
		int x = find(item.first);   //寻找数轴值在离散化后序列中的位置
		a[x] += item.second;    //相应位置插入值
	}
	//预处理前缀和
	for (int i = 1; i <= alls.size(); i ++) s[i] = s[i - 1] + a[i];
	for (auto item : query) {
		//获得数轴上的询问数对{l, r}离散化后的值
		int l = find(item.first), r = find(item.second);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}
