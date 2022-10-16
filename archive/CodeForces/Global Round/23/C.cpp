#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 1e5 + 10;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, arr[M];
        vector<pair<int, int>> diff;
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> arr[i];
            if (arr[i] < arr[i - 1]) diff.push_back({arr[i - 1] - arr[i], i});
        }
        sort(diff.begin(), diff.end());
        // cout << diff[0].first << " " << diff[0].second << '\n';
        int idx = 0;
        for (int i = 1; i <= n; i ++) {
            if (idx >= diff.size()) {cout << 1 << " "; continue; }
            if (diff[idx].first <= i) {
                cout << diff[idx].second << " ";
                idx ++;
            } else {
                cout << diff[idx].second << " ";
                diff[idx].first -= i;
            }
        }
        cout << '\n';
    }   
    return 0;
}