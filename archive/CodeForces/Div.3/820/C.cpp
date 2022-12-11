#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int k = 1;
        string str;
        vector<int> ans;
        vector<vector<int>> v(30);
        cin >> str;
        for (auto xi : str)
            v[xi - 'a'].push_back(k ++);
        int l = str.front() - 'a' + 1, r = str.back() - 'a' + 1;
        if (l <= r) {
            for (int i = l; i <= r; i ++)
                for (auto xi : v[i - 1])
                    ans.push_back(xi);
        } else {
            for (int i = l; i >= r; i --)
                for (auto xi : v[i - 1])
                    ans.push_back(xi);
        }
        cout << abs(l - r) << " " << ans.size() << '\n';
        for (auto xi : ans) cout << xi << " ";
        cout << '\n';
    }
    return 0;
}