#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int INF = 0x3f3f3f3f;
int check(char x) {
    if (x == '&' || x == '#' || x == '*') return 1;
    else if (x >= 'a' && x <= 'z') return 2;
    else return 3;
}
int main() {
    IOS

    int n, m;
    cin >> n >> m;

    vector<string> vs(n + 1);
    vector<pair<int, int>> spcial, letter, num;

    for (int i = 1; i <= n; i ++) {
        cin >> vs[i];
        int sp = INF, le = INF, nu = INF;
        for (int j = 0; j < m; j ++) {
            int type = check(vs[i][j]);
            int minDis = min(j, m - j);

            if (type == 1) sp = min(sp, minDis);
            else if (type == 2) le = min(le, minDis);
            else if (type == 3) nu = min(nu, minDis);

        }

        if (sp != INF) spcial.push_back({sp, i});
        if (le != INF) letter.push_back({le, i});
        if (nu != INF) num.push_back({nu, i});

    }

    sort(spcial.begin(), spcial.end());
    sort(letter.begin(), letter.end());
    sort(num.begin(), num.end());

    int ans = INF;
    for (int i = 0; i < min(5, (int)spcial.size()); i ++) {
        for (int j = 0; j < min(5, (int)letter.size()); j ++) {
            if (letter[j].second == spcial[i].second) continue;
            for (int k = 0; k < min(5, (int)num.size()); k ++) {
                if (num[k].second == spcial[i].second || num[k].second == letter[j].second) continue;
                ans = min(ans, spcial[i].first + letter[j].first + num[k].first);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}