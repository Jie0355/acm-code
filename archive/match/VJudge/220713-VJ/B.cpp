#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int M = 1e5 + 10;
ll unSortedArr[M], SortedArr[M];
int main() {
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        ll x;
        cin >> x;
        SortedArr[i] = unSortedArr[i] = x;
    }
    sort(SortedArr + 1, SortedArr + n + 1);
    int i = 1, j = n;
    while (SortedArr[i] == unSortedArr[i] && i <= n) i ++;
    while (SortedArr[j] == unSortedArr[j] && j > 0) j --;
    //printf("%d %d\n", i, j);
    // if (i == n + 1 && j == 0) {
    //     printf("yes\n1 1");
    //     return 0;
    // }
    int start = i, end = j, flag = 1;
    while (start <= end) {
        if (unSortedArr[start] != SortedArr[end] || unSortedArr[end] != SortedArr[start]) flag = 0;
        start ++; end --;
    }
    if (flag) printf("yes\n%d %d", i, j);
    else printf("no\n");
    return 0;
}