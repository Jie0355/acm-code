#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int popcount(int u) {
	int cnt = 0;
	while (u) {
		u &= u - 1;
		cnt ++;
	}
	return cnt;
}

int lowbit(int x) {
	return x & (-x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}