#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int M = 2e5 + 10;
int main() {
    IOS;
    int n, d[M];
    ll A, sum = 0, ans;
    cin >> n >> A;
    for (int i = 0; i < n; i ++) {
        cin >> d[i];
        sum += d[i];
    }
    ll up, low; //可行区间上下限
    for (int i = 0; i < n; i ++) {
        up = min((ll)d[i], A - n + 1); //其余骰子取最小值 此位置取上限
        low = max((ll)1, A - sum + d[i]); //其余骰子取最大值 此位置取下限
        ans = d[i] - (up - low + 1); //不可行区间值数
        cout << ans << ' ';
    }
    return 0;
}