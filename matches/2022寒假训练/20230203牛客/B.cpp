#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;

int arr[M * 2];
vector<vector<int>> VV(M);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, query;
    cin >> n >> query;

    for (int i = 1, x; i <= n; i ++) {
        cin >> arr[i]; x = arr[i];
        for (int j = 1; j <= sqrt(x); j ++) {
            if (x % j == 0) {
                VV[j].push_back(i);
                if (x / j != j) VV[x / j].push_back(i);
            }
        }
    }

    while (query --) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            n ++;
            arr[n] = x;
            for (int i = 1; i <= sqrt(x); i ++) {
                if (x % i == 0) {
                    VV[i].push_back(n);
                    if (x / i != i) VV[x / i].push_back(n);
                }
            }
        } else {
            int num = arr[x];
            int pos = upper_bound(VV[num].begin(), VV[num].end(), x) - VV[num].begin();
            int ans = VV[num].size() - pos;
            cout << ans << '\n';
        }
    }

    return 0;
}