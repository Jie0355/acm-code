#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e5 + 10;
void solve() {
    int n;
    pair<int, int> arr[M];
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        arr[i] = {x, i};
    }
    sort(arr + 1, arr + n + 1);
    int pre = arr[1].first;
    vector<pair<int, int>> ans;
    for (int i = 2; i <= n; i ++) {
        int l = arr[i].first / pre * pre;
        int r = (arr[i].first / pre + 1) * pre;
        if (arr[i].first == l) {
            pre = l;
            continue;
        } else {
            pre = r;
            ans.push_back({arr[i].second, r - arr[i].first});
        }
    }
    cout << ans.size() << '\n';
    for (auto xi : ans) {
        cout << xi.first << " " << xi.second << '\n';
    }
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) solve();
    return 0;
}