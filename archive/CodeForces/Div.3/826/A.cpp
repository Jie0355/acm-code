#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
unordered_map<char, int> mp;
int main() {
    IOS
    mp['S'] = 0, mp['M'] = 1, mp['L'] = 2;
    int t;
    cin >> t;
    while (t --) {
        string a, b;
        cin >> a >> b;
        if (mp[a[a.size() - 1]] - mp[b[b.size() - 1]] > 0) cout << ">" << '\n';
        else if (mp[a[a.size() - 1]] - mp[b[b.size() - 1]] < 0) cout << "<" << '\n';
        else {
            if (a.size() == b.size()) cout << "=" << '\n';
            else if (a[a.size() - 1] == 'S') {
                if (a.size() > b.size()) cout << "<" << '\n';
                else cout << ">" << '\n';
            }
            else {
                if (a.size() > b.size()) cout << ">" << '\n';
                else cout << "<" << '\n';
            }
        }
    }
    return 0;
}