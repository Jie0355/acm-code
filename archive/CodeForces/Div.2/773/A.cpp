// Hard Way
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
struct Point {
	int x, y;
} arr[3];
int cmp(struct Point a, struct Point b) {
	return a.y > b.y;
}
int main() {
	IOS;
	int t;
	cin >> t;
	while (t --) {
		for (int i = 0; i < 3; i ++) cin >> arr[i].x >> arr[i].y;
		sort(arr, arr + 3, cmp);
		if (arr[0].y == arr[1].y) cout << abs(arr[0].x - arr[1].x) << endl;
		else cout << 0 << endl;
	}
	return 0;
}
