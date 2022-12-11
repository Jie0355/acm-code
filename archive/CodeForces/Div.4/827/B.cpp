#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n;
        long long arr[110];
        cin >> n;
        for (int i = 0; i < n; i ++) cin >> arr[i];
        sort(arr, arr + n);
        bool flag = true;
        for (int i = 1; i < n; i ++) {
            if (arr[i] == arr[i - 1]) {
                flag = false;
                break;               
            }
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}