#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    IOS;
    int n, arr[110][110] = {0};
    vector<int> ans;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) 
            cin >> arr[i][j];
    for (int i = 1; i <= n; i ++) {
        bool flag = true;
        for (int j = 1; j <= n; j ++) {
            if (i != j) {
                if (arr[i][j] == arr[j][i] && arr[i][j]) {
                    flag = false;
                    break;
                }
                else if (arr[i][j] == 1 && arr[j][i] == 2) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i ++) cout << ans[i] << ' ';
    return 0;
}