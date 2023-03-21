//831.KMP字符串
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;
/*
str1->模式串 str2->模板串
ne[]->对于next[i]->是p[1, i]串中前缀和后缀相同的最大长度
*/
char str1[M], str2[N];
int n, m, ne[N];
int main() {
	cin >> n >> str2 + 1 >> m >> str1 + 1;
	//GetNextArray
	ne[1] = 0;
	int idx = 0;
	for (int i = 2; i <= n; i ++) {
		while (idx && str2[i] != str2[idx + 1]) idx = ne[idx];
		if (str2[i] == str2[idx + 1]) idx ++ ;
		ne[i] = idx;
	}
	//KMP
	for (int i = 1, j = 0; i <= m; i ++ ) {
		while (j && str1[i] != str2[j + 1]) j = ne[j];
		if (str1[i] == str2[j + 1]) j ++ ;
		if (j == n) {
			cout << i - n << ' ';
			j = ne[j];
		}
	}
	return 0;
}
