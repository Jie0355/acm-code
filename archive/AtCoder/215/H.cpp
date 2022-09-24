#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e5 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

int n, m;
int arr[M], vis[M] = {0}, ans[M];

//分解质因子
void div(int num) {
    for (int i = 2; i <= sqrt(num); i ++) {
        if (!(num % i)) {
            vis[i] = 1;
            while(!(num % i)) num /= i;
        }
    }
    if (num > 1) vis[num] = 1;
}

//去除质因子倍数
void preprocess(void) {
    for (int i = 0; i <= m; i ++) if (vis[i]) for (int j = i; j <= m; j += i) vis[j] = 1;
}

int main() {
    IOS;
    int k = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        div(arr[i]);
    }
    preprocess();
    for (int i = 1; i <= m; i ++) if (!vis[i]) ans[k ++] = i;
    cout << k << endl;
    for (int i = 0; i < k; i ++) cout << ans[i] << endl;
    return 0;
}
