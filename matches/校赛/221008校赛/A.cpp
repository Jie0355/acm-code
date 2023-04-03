#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, m;
	string str[110];
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> str[i];
	while (m --) {
		int flag = 0;
		string t;
		cin >> t;
		for (int i = 0; i < n; i ++)
			if (t.find(str[i]) != t.npos) {flag = 1; break;}
		if (flag) cout << "bieexina" << endl;
		else cout << "enenen" << endl;
	}
	return 0;
}