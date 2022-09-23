#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int M = 2e5 + 10;
typedef long long ll;
struct goods {
    int now, after, minus;
}good[M];
bool cmp(struct goods a, struct goods b) {
    return a.minus < b.minus;
}
int main() {
    IOS;
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> good[i].now;
    for (int i = 0; i < n; i ++) {
        cin >> good[i].after;
        good[i].minus = good[i].now - good[i].after;
    }
    sort(good, good + n, cmp);
    int i, j;
    for (i = 0; good[i].minus < 0; i ++) ans += good[i].now;
    for (j = i; j < n; j ++) {
        if (j < k) ans += good[j].now;
        else ans += good[j].after;
    }
    cout << ans;
    return 0;
}