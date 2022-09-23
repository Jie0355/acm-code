#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main() {
    IOS;
    int n, k, x;
    int arr[110] = {0};
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i ++) cin >> arr[i];
    int loc = 2, res = 0, ans;
    while (loc <= n - 2) {
        if (arr[loc] == arr[loc + 1] && arr[loc] == x) {
            ans = 2;
            for (int i = loc - 1, j = loc + 2; arr[i] == arr[j] && i > 0 && j <= n; i --, j ++) {
                if (arr[i - 1] == arr[i] || arr[j + 1] == arr[j]) {
                    ans += 2;
                    if (arr[i - 1] == arr[i] && i > 1) i --, ans ++;
                    if (arr[j + 1] == arr[j] && j < n) j ++, ans ++;
                }
                else break;
            }
            res = max(res, ans);
        }
        loc ++;
    }
    cout << res;
    return 0;
}