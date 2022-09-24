#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, n, m;
    int a[1005], b[1005];
    scanf("%d", &T);
    while (T --) {
        int breakflag = 0;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i ++) scanf("%d", &b[i]);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (a[i] == b[j]) {
                    breakflag = 1;
                    printf("YES\n1 %d\n", a[i]);
                    break;
                }
            }
            if (breakflag) break;
        }
        if (!breakflag) printf("NO\n");
    }
    return 0;
}