//154.滑动窗口
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

//q[]->arr[]下标
int arr[N], q[N], head, tail;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> arr[i];
    //OutputMinArray
    int head = 0, tail = -1;
    for (int i = 0; i < n; i ++ ) {
        if (head <= tail && i - k + 1 > q[head]) head ++ ; //队首出窗口
        while (head <= tail && arr[q[tail]] >= arr[i]) tail -- ; //新元素插入后 仍然保持栈严格单调递增
        q[++ tail] = i; //插入新元素下标
        if (i >= k - 1) cout << arr[q[head]] << ' ';
    }
    cout << endl;
    //OutputMaxArray
    head = 0, tail = -1; //重置 下同
    for (int i = 0; i < n; i ++ ) {
        if (head <= tail && i - k + 1 > q[head]) head ++ ;
        while (head <= tail && arr[q[tail]] <= arr[i]) tail -- ;
        q[++ tail] = i;
        if (i >= k - 1) cout << arr[q[head]] << ' ';
    }
    cout << endl;
    return 0;
}