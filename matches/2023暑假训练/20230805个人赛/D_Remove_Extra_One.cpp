#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int arr[M];
    for (int i = 0; i < n; i ++) cin >> arr[i];

    int attr[M] = {0};
    pair<int, int> maxV = {0, 0};
    for (int i = 0; i < n; i ++) {
        if (arr[i] > maxV.first) {
            maxV = {arr[i], maxV.first};
            attr[arr[i]] --;
        } else if (arr[i] > maxV.second) {
            maxV.second = arr[i];
            attr[maxV.first] ++;
        }
    }
    
    int ans, maxAttr = -INF;
    for (int i = 1; i <= n; i ++) {
        if (attr[i] > maxAttr) {
            maxAttr = attr[i];
            ans = i;
        }
    }

    cout << ans << '\n';

    return 0;
}