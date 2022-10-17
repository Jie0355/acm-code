#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, res = 0;
        char now;
        string str;
        vector<int> posR, posG;
        cin >> n >> now >> str;
        if (now == 'g') {cout << 0 << '\n'; continue;}
        for (int i = 0; i < str.size(); i ++)
            if (str[i] == 'g') posG.push_back(i + 1);
            else if (str[i] == now) posR.push_back(i + 1);
        for (int i = 0; i < posR.size(); i ++) {
            int ans;
            if (posR[i] > posG.back()) ans = n - posR[i] + posG.front();
            else {
                int pos = upper_bound(posG.begin(), posG.end(), posR[i]) - posG.begin();
                ans = posG[pos] - posR[i];
            }
            res = max(res, ans);
        }
        cout << res << '\n';
    }   
    return 0;
}