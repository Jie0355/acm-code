#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e3 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> vs;
    unordered_map<string, string> mp;
    for (int i = 0; i < n; i ++) {
        string s, t;
        cin >> s >> t;
        if (mp.find(s) == mp.end()) vs.push_back(s);
        mp[s] = t;
        mp[t] = "#";
    }

    cout << vs.size() << '\n';
    for (auto ss : vs) {
        cout << ss << " ";
        while (mp[ss] != "#") {
            ss = mp[ss];
        }
        cout << ss << '\n';
    }

    return 0;
}