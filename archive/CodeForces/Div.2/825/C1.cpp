#include <iostream>
using namespace std;
const int M = 2e5 + 10;
int main() {
    int t;
    cin >> t;
    while (t --) {
        int n, arr[M];
        long long ans = 0;
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> arr[i];
        for (int i = 0, j = 0; i < n; i ++) {
            while (j < n && arr[j] - (j - i + 1) >= 0) j ++;
            ans += j - i;
        }
        cout << ans << '\n';
    }
    return 0;
}