#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, flag = 1;
        string str;
        vector<int> arr, alp;
        unordered_map<int, int> ans;
        cin >> n;
        for (int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        cin >> str;
        for (auto xi : str) alp.push_back(xi - 'a');
        for (int i = 0; i < n; i ++) {
            if (ans.find(arr[i]) == ans.end()) {
                ans[arr[i]] = alp[i];
                continue;
            }
            if (ans[arr[i]] != alp[i]) {flag = 0; break;}
        }
        if (!flag) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}