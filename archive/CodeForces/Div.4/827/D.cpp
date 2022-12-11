#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
inline int Gcd(int a, int b)  {  
    while(b ^= a ^= b ^= a %= b);
    return a;
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, arr[1010] = {0};
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            int x;
            cin >> x; 
            arr[x] = i;
        }
        int ans = -1;
        for (int i = 1; i <= 1000; i ++) {
            for (int j = 1; j <= 1000; j ++) {
                if (arr[i] && arr[j] && Gcd(i, j) == 1)
                    ans = max(ans, arr[i] + arr[j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}