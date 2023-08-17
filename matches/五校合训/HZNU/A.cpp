#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int n;
int arr[M];

int check(int k) {
    int pre;
    stack<int> stk;
    for (int i = 0; i < n; i ++) {
        if (stk.size()) pre = stk.top();
        else pre = -1;
        if (arr[i] < k) stk.push(0);
        else if (arr[i] > k) stk.push(1);
        if (pre == 0 && stk.top() == 1) {
            stk.pop();
            stk.pop();
        }
    }
    if (!stk.size()) return 0;
    else {
        if (stk.top() == 0) return 1; // '('
        else if (stk.top() == 1) return 2; // ')'
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int minV = INF, maxV = -1;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        minV = min(minV, arr[i]);
        maxV = max(maxV, arr[i]);
    }

    // for (int i = minV; i <= maxV; i ++) {
    //     cout << i << " ";
    //     if (check(i) == 0) cout << "YES" << '\n';
    //     else cout << "NO" << '\n';
    // }

    int ans_l, ans_r;

    int l = minV, r = maxV;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid) == 0) r = mid;
        else {
            if (check(mid) == 1) r = mid - 1;
            else if (check(mid) == 2) l = mid + 1;
        }
    }
    ans_l = l;

    // cout << l << " " << r << '\n';

    l = minV, r = maxV;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid) == 0) l = mid;
        else {
            if (check(mid) == 1) r = mid - 1;
            else if (check(mid) == 2) l = mid + 1;
        }
    }
    ans_r = l;

    // cout << l << " " << r << '\n';

    if (ans_l > ans_r) cout << 0 << '\n';
    else if (ans_l == ans_r) {
        if (check(ans_l) == 0) cout << 1 << '\n';
        else cout << 0 << '\n';
    } else cout << ans_r - ans_l + 1 << '\n';

    return 0;
}