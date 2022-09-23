//康托展开（Cantor Expansion）
#include <bits/stdc++.h>
using namespace std;
long long factorial(int x)
{
	if (x <= 1) return 1;
	else return (factorial(x - 1) * x);
}
int Cantor(const char *x)
{
	int len = strlen(x), sum = 1;

	for (int i = 0; i < len; i++) {
		int cmp = 0;
		for (int j = i+1; j < len; j++) {
			if (x[i] > x[j])cmp ++;
		}
		sum += cmp * factorial((len - i - 1));
	}
	return sum;
}
int main() {
	char str[1005];
	scanf("%s", str);
	printf("%d", Cantor(str));
	return 0;
}