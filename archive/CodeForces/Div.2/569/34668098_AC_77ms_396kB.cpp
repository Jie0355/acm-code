//D
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e5 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

int main() {
    IOS;
    int n, arr[M];
    int lowNum = 0, flag = -1;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        if (arr[i] >= 0) arr[i] = -1 * arr[i] - 1;
        if (arr[i] < lowNum) {
            lowNum = arr[i];
            flag = i;
        }
    }
    if (n & 1) arr[flag] = -1 * arr[flag] - 1;
    for (int i = 0; i < n; i ++) {
        cout << arr[i] << " ";
    }
    return 0;
}