#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int t;
    cin>> t;
    while (t --) {
        int n, i;
        string str, ans;
        cin >> n >> str;
        i = str.size() - 1;
        while (i >= 0) {
            int idx;
            if (str[i] == '0') {
                idx = (str[i - 2] - '0') * 10 + str[i - 1] - '0' - 1;
                ans.push_back(idx + 'a');
                i -= 3;
            } else {
                idx = str[i] - '0' - 1;
                ans.push_back(idx + 'a');
                i --;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
    return 0;
}