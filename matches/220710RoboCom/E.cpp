#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e4 + 10;
int Gph[M][M] = {0};
vector<pair<ll, ll>> ans;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        ll a, b;
        cin >> a >> b;
        Gph[a][b] = Gph[b][a] = 1;
    }
    vector<ll> v;
    for (int i = 1; i <= n; i ++) {
        for (int o = 1; o <= n; o ++) {
            if (Gph[i][o] == 1) v.push_back(o);
        }
        if (!v.size()) continue;
        int tmpsize = v.size();
        for (int o = 0; o < tmpsize; o ++) {
            for (int j = 1; j <= n; j ++) {
                if (Gph[v[o]][j] && find(v.begin(), v.end(), j) == v.end())
                    v.push_back(j);
            }
        }
        // for (int o = 0; o < v.size(); o ++) {
        //     printf("%d ", v[o]);
        //     if (o == v.size() - 1) printf("\n");
        // }
        for (ll o = 1; o <= n; o ++) {
            if (find(v.begin(), v.end(), o) == v.end()) {
                int findio = 0;
                for (int j = 0; j < ans.size(); j ++) {
                    if ((ans[j].first == i && ans[j].second == o) || (ans[j].first == o && ans[j].second == i)) {
                        findio = 1;
                        break;
                    }
                }
                if (!findio) {
                    ans.push_back({i, o});
                    // for (int o = 0; o < ans.size(); o ++) {
                    //     auto x = ans[o].first, y = ans[o].second;
                    //     printf("{%d, %d}", x, y);
                    //     if (o == ans.size() - 1) printf("\n");
                    // }
                 }
            }
        }
        v.clear();
    }
    printf("%d", ans.size());
    return 0;
}