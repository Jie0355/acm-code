#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
int main() {
    int T, n;
    int arr[M];
    scanf("%d", &T);
    while (T --) {
        int cnt = 0, flag = 0, i;
        scanf("%d", &n);
        for (i = 0; i < n; i ++) scanf("%d", &arr[i]);
        for (i = 0; i < n; i ++) {
            if (arr[i] == 1) cnt ++;
            else {
                flag = 1;
                if ((i + 1) & 1) printf("First\n");
                else printf("Second\n");
                break;
            }
        }
        if (!flag) {
            if ((i + 1) & 1) printf("Second\n");
            else printf("First\n");
        }
    }
    return 0;
}