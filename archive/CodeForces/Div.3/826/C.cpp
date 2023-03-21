#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
const int M = 2e3 + 10, INF = 0x3f3f3f3f;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, arr[M];
        cin >> n;
        int arrMax = 0;
        LL sum = 0;
        for (int i = 0; i < n; i ++) {
            cin >> arr[i];
            sum += arr[i];
            arrMax = max(arrMax, arr[i]);
        }
        int k = 0;
        LL aim[M];
        for (int i = 2; i <= n; i ++) {
            if (!(sum % i) && (sum / i) >= arrMax)
                aim[k ++] = sum / i;
        }
        int thickMin = INF;
        for (int i = 0; i < k; i ++) {
            int idxPre = 0, idxNow = 0;
            int thick = 0, fg = 0;
            LL sumNow = 0;
            for (; idxNow <= n; idxNow ++) {
                if (sumNow == aim[i]) {
                    idxNow --;
                    sumNow = 0;
                    thick = max(thick, idxNow - idxPre + 1);
                    idxPre = idxNow + 1;
                }
                else if (sumNow < aim[i]) sumNow += arr[idxNow];
                else {fg = 1; break;}
            }
            if (!fg) thickMin = min(thickMin, thick);
        }
        if (thickMin == INF) cout << n << '\n';
        else cout << thickMin << '\n';
    }
    return 0;
}