#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e4 + 7;
const int MOD = 1e9 + 7;

int n, t, l, r;
int arr[M];
LL ans = 0;

int main() {
    IOS;
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> arr[i];
    for (int i = 0; i < n; i ++) {
        for (int j = i; j < n; j ++) {
            if (arr[i] > arr[j]) ans ++;
        }
    }
    cin >> t;
    while (t --) {
        cin >> l >> r;
        if (ans & 1) {
            if (((r - l + 1) / 2) % 2) {
                cout << "even" << endl;
                ans ++;
            }
            else cout << "odd" << endl;
        }
        else {
            if (((r - l + 1) / 2) % 2) {
                cout << "odd" << endl;
                ans ++;
            }
            else cout << "even" << endl;
        }
    }
    return 0;
}