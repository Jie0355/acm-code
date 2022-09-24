//B
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e5 + 7;
const int MOD = 1e9 + 7;

int main() {
    IOS;
    int n;
    LL arr[M];
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> arr[i];
    for (int i = 0; i < n; i ++) {
        if (i == 0) {
            printf("%lld %lld\n", arr[i + 1] - arr[i], arr[n - 1] - arr[i]);
        }
        else if (i == n - 1) {
            printf("%lld %lld\n", arr[i] - arr[i - 1], arr[i] - arr[0]);
        }
        else {
            LL cl = min(arr[i] - arr[i - 1], arr[i + 1] - arr[i]);
            LL fr = max(arr[n - 1] - arr[i], arr[i] - arr[0]);
            printf("%lld %lld\n", cl, fr);
        }
    }
    return 0;
}