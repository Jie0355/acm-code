#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e3 + 7;
const int MOD = 1e9 + 7;

int main() {
    IOS;
    int n, r;
    double x[M], y[M];
    cin >> n >> r;
    for (int i = 0; i < n; i ++) {
        cin >> x[i];
        y[i] = r;
        for (int j = 0; j < i; j ++) {
            double ans;
            ans = sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j])) + y[j];
            if (ans > y[i]) y[i] = ans;
        }
        printf("%.10lf ", y[i]);
    }
    return 0;
}