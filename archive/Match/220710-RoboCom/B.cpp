#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e3 + 10;
int take[M];
ll drug[M];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    memset(drug, -1, sizeof(drug));
    for (int i = 1; i <= n; i ++) cin >> take[i];
    while (m --) {
        int k;
        ll t;
        cin >> t >> k;
        for (int i = 0; i < k; i ++) {
            int no;
            cin >> no;
            if (take[no] == -1) continue;
            if (drug[no] == -1) drug[no] = t;
            else if (t - drug[no] < take[no]) printf("Don't take %d at %lld!\n", no, t);
            else drug[no] = t;
        }
    }
    return 0;
}