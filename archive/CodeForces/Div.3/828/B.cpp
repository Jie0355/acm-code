#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, query, cntOdd = 0, cntEven = 0;
        LL sumOdd = 0, sumEven = 0;
        cin >> n >> query;
        for (int i = 0; i < n; i ++) {
            LL x;
            cin >> x;
            if (x & 1) {
                sumOdd += x;
                cntOdd ++;
            } else {
                sumEven += x;
                cntEven ++;
            }
        }
        while (query --) {
            int d, x;
            cin >> d >> x;
            if (d) {
                sumOdd += cntOdd * x;
                if (x & 1) cntEven += cntOdd, cntOdd = 0;
            } else {
                sumEven += cntEven * x;
                if (x & 1) cntOdd += cntEven, cntEven = 0;
            }
            cout << sumOdd + sumEven << '\n';
        }
    }
    return 0;
}