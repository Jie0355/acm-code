#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, cnt = 0;
    unsigned long long sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n ; i ++) {
        unsigned long long x;
        cin >> x;
        if (sum + x > m) {
            cnt ++;
            sum = 0;
        }
        sum += x;
    }
    cout << cnt;
    return 0;
}