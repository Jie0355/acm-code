#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
void out(string t) {
	if (t.size() == 1) printf("%c", t[0] - 'a' + 'A');
	else {
		for (int i = 0; i < t.size(); i ++) {
			if (i == t.size() - 1) printf("%c", t[i] - 'a' + 'A');
			else printf("%c", t[i]);
		}
	}
}
int main() {
	IOS
	int t;
	cin >> t;
	while (t --) {
		string str, t;
		cin >> str;
		for (int i = 0; i < str.size(); i ++) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				if (t.size()) {
					out(t);
					t.clear();
				}
				t.push_back(str[i] - 'A' + 'a');
			} else t.push_back(str[i]);
		}
		if (t.size()) out(t);
		printf("\n");
	}
	return 0;
}