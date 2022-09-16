//875.快速排序
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6+10;

int q[MAX_N], n;

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}

//876.快速排序实现第K个数
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

int n, k;
int q[MAX_N];

int quick_sort(int l, int r, int k) {
    if (l == r) return q[l];
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i ++; while (q[i] < x);
        do j --; while (q[j] > x);
        if (i < j) swap(q[i],q[j]);
    }
    int sl = j - l + 1;
    if(k <= sl) return quick_sort(l, j, k);
    return quick_sort(j + 1, r, k - sl);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    printf("%d", quick_sort(0, n-1, k));
    return 0;
}