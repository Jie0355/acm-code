#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;

pair<int, int> w[M];
pair<i64, i64> sum[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int cnt;

    cnt = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'u') cnt ++;
        else if (s[i] == 'd') w[i].first = cnt;
        if (s[i] == 'd') sum[i].first = sum[max(i - 1, 0)].first + w[i].first;
        else sum[i].first = sum[max(i - 1, 0)].first;
    }

    cnt = 0;
    for (int i = s.size() - 1; i >= 0; i --) {
        if (s[i] == 'u') cnt ++;
        else if (s[i] == 'd') w[i].second = cnt;
        if (s[i] == 'd') sum[i].second = sum[min(i + 1, (int)s.size() - 1)].second + w[i].second;
        else sum[i].second = sum[min(i + 1, (int)s.size() - 1)].second;
    }

    // for (int i = 0; i < s.size(); i ++) {
    //     cout << w[i].first << " " << w[i].second << '\n';
    // }

    // for (int i = 0; i < s.size(); i ++) {
    //     cout << sum[i].first << " " << sum[i].second << '\n';
    // }

    int pos = -1;
    i64 ans = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == 'd') {
            i64 con = w[i].first * w[i].second;
            if (con > ans) {
                ans = con;
                pos = i;
            }
        } else if (s[i] == 'u') {
            i64 con = sum[i].first + sum[i].second;
            if (con > ans) {
                ans = con;
                pos = i;
            }
        }
    }

    if (pos != -1) s[pos] = 'x';
    cout << s << '\n';

    return 0;
}