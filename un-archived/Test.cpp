#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
ll rr() {
    ll s = 0, w = false, c = getchar();
    for (; !isdigit(c); c = getchar())
        w = w || c == '-';
    for (; isdigit(c); c = getchar())
        s = s * 10 + c - '0';
    return w ? -s : s;
}
int main() {
	IOS
	int n;
	n = rr();
	n = pow(2, n);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++)
			if ((i | j) == n - 1) cout << 1 << " ";
			else cout << 0 << " ";
		cout << '\n';
	}
	return 0;
}
