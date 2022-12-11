#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
const int M = 2e5 + 10;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int n, arr[M];
        string str;
        cin >> n >> str;
        for (int i = 0; i < n; i ++) cin >> arr[i];
        for (int i = 0, j = -1; i < n; i ++) {
            if (str[i] == '0') {
                j = i;
            } else if (j != -1 && arr[j] > arr[i]) {
                swap(str[i], str[j]);
                j = i;
            }
        }
        LL sum = 0;
        for (int i = 0; i < n; i ++)
            if (str[i] == '1') sum += arr[i];
        cout << sum << '\n';
    }
    return 0;
}