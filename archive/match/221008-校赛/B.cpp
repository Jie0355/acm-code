#include <iostream>
using namespace std;
int main() {
	int n, arr[5010];
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> arr[i];
	int st = 0, tm, idx = 0;
	while (st < n) {
		tm = 0;
		for (int i = st; i < n; i ++)
			if (arr[i] > tm) {tm = arr[i]; idx = i;}
		for (int i = idx; i >= st; i --) cout << arr[i] << " ";
		st = idx + 1;
	}
	return 0;
}