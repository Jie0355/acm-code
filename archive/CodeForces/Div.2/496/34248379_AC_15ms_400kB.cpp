#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
int main() {
    int i, j, ans = 0;
    char str1[MAX], str2[MAX];
    scanf("%s", str1);
    getchar();
    scanf("%s", str2);
    int len1 = strlen(str1), len2 = strlen(str2);
    for (i = len1 - 1, j = len2 - 1;;) {
        if (str1[i] == str2[j]) {
            i --; j --;
        }
        else break;
        if (i < 0 || j < 0) break;
    }
    ans = i + j + 2;
    printf("%d", ans);
    return 0;
}