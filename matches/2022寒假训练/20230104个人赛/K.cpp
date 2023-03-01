#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

unordered_map<char, int> mp;

string dis(string t) {
    string ans;
    for (int i = 0; i < t.size(); i ++)
        ans.push_back(mp[t[i]] + '0');
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int pos = 2, cnt = 0;
    for (char i = 'a'; i <= 'z'; i ++) {
        if (i == 's') {mp[i] = 7; continue; }
        if (cnt < 3) {
            mp[i] = pos;
            cnt ++;
        } else {
            cnt = 1;
            pos ++;
            mp[i] = pos;
        }
    }
    mp['z'] = 9;

    int n, query;
    cin >> n >> query;

    unordered_map<string, int> ip;
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        ip[dis(s)] ++;
    }

    while (query --) {
        string s;
        cin >> s;
        cout << ip[s] << '\n';
    }

    return 0;
}