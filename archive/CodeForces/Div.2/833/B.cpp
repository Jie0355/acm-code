#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n;
        vector<int> arr;
        string str;
        cin >> n >> str;
        for (int i = 0; i < n; i ++)
            arr.push_back(str[i] - '0');
        int res = 0, cnt[10] = {0};
        for (int i = 0; i < n; i ++) {
            int ans = 0, t[10] = {0};
            cnt[arr[i]] ++;
            for (int j = max(0, i - 100); j <= i; j ++)
                t[arr[j]] ++;
            for (int j = max(0, i - 100); j <= i; j ++) {
                int diff = 0, maxLen = 0;
                for (int o = 0; o <= 9; o ++)
                    if (t[o]) maxLen = max(maxLen, t[o]), diff ++;
                if (maxLen <= diff) ans ++;
                t[arr[j]] --;
            }
            res += ans;
        }
        cout << res << '\n';
    }
    return 0;
}