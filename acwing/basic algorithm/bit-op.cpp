//801.二进制中1的个数
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n --) {
        int x, sum = 0;
        scanf("%d", &x);
        for (int i = x; i; i -= i & -i) sum ++;
        printf("%d ", sum);
    }
    return 0;
}