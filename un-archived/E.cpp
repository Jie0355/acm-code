// E An Interesting Sequence
#include <bits/stdc++.h>
using namespace std;
const int M = 110;
int pr[M];
void prime() {
    int k = 1;
    pr[0] = 2;
    for (int i = 3; i <= 100; i ++) {
        int flag = 1;
        for (int j = 2; j <= sqrt(i); j ++)
            if (!(i % j)) {flag = 0; break;}
        if (flag) pr[k ++] = i;
    }
    // for (int i = 0; i < k; i ++) cout << pr[i] << " ";
}
int main() {
    prime();
    int n, k;
    cin >> n >> k;
    int ans = k;
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < 20; j ++) {
            if (k % pr[j]) {
                ans += pr[j];
                k = pr[j];
                break;
            }
        }
    }
    cout << ans;
}