#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 3e5 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

int main() {
    IOS;
    int n, k, candy[M];
    map<int, int> NofD;
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> candy[i];
    for (int i = 0; i < k; i ++) NofD[candy[i]] ++;
    int cnt = NofD.size();
    if (k < n) {
        for (int i = k; i < n; i ++) {
            NofD[candy[i]] ++;
            NofD[candy[i - k]] --;
            if (!NofD[candy[i - k]]) NofD.erase(candy[i - k]);
            cnt = cnt < NofD.size() ? NofD.size() : cnt;
        }
    }
    cout << cnt;
    return 0;
}
