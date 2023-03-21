#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
const int M = 2e5 + 10;
LL arr[M], arrMax[M], sum[M];
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, query;
        LL arrTmax = 0;
        memset(arr, 0, sizeof arr);
        memset(sum, 0, sizeof sum);
        cin >> n >> query;
        for (int i = 0; i < n; i ++) {
            cin >> arr[i];
            arrTmax = max(arrTmax, arr[i]);
            arrMax[i] = arrTmax;
            if (!i) sum[i] = arr[i];
            else sum[i] = sum[i - 1] + arr[i];
        }
        // for (int i = 0; i < n; i ++) cout << arrMax[i] << " ";
        // for (int i = 0; i < n; i ++) cout << sum[i] << " ";
        while (query --) {
            LL l;
            cin >> l;
            int idx = upper_bound(arrMax, arrMax + n, l) - arrMax;
            cout << sum[idx - 1] << " ";
        }
        cout << '\n';
    }
    return 0;
}