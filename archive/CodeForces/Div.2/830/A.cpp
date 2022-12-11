#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
inline int Gcd(int x, int y) {
    while (y ^= x ^= y ^= x %= y);
    return x;
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, arr[25];
        cin >> n;
        int nx = -1, cost = 0;
        for (int i = 1; i <= n; i ++) cin >> arr[i];
        for (int i = 1; i <= n; i ++) {
            for (int j = i; j <= n; j ++)
                if (Gcd(arr[i], arr[j]) == 1) {nx = 0; break;}
            if (!nx) break;
        }
        if (!nx) {cout << cost << '\n'; continue;}
        // The Last
        int t = Gcd(arr[n], n);
        cost = 1;
        if (t == 1) {cout << cost << '\n'; continue;}
        for (int i = n; i >= 1; i --)
            if (Gcd(t, arr[i]) == 1) nx = 1;
        if (nx == 1) {cout << cost << '\n'; continue;}
        // Second Last
        t = Gcd(arr[n - 1], n - 1);
        cost = 2;
        if (t == 1) {cout << cost << '\n'; continue;}
        for (int i = n; i >= 1; i --)
            if (Gcd(t, arr[i]) == 1) nx = 2;
        if (nx == 2) {cout << cost << '\n'; continue;}
        // Both
        cout << 3 << '\n';
    }   
    return 0;
}