//E
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 3e5 + 7;
const int MOD = 1e9 + 7;

int n, k, cnt;
int arr[M], sum[M] = {0};

int main() {
    IOS;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + (!arr[i]);
    }
    // for (int i = 1; i <= n; i ++) cout << sum[i];
    int l, r, start = 0, end = 0;
    for (int i = 1; i <= n; i ++) {
        l = i, r = n;
        while (l <= r) {
            int mid = l + r >> 1;
            if (sum[mid] - sum[i - 1] <= k) {
                if (mid - i + 1 > cnt) {
                    cnt = mid - i + 1;
                    start = i; end = mid;
                }
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i ++) {
        if (i >= start && i <= end) cout << 1 << ' ';
        else cout << arr[i] << ' ';
    }
    return 0;
}