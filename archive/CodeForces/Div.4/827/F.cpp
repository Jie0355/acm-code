#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long LL;
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        int query;
        LL cnt[2] = {0};
        bool found[2] = {false};
        cin >> query;
        while (query --) {
            int d, k;
            string x;
            cin >> d >> k >> x; d --;
            for (int i = 0; i < x.size(); i ++) {
                if (x[i] == 'a') cnt[d] += k;
                else found[d] = true;
            }
            if (found[1]) cout << "YES" << '\n';
            else if (found[0]) cout << "NO" << '\n';
            else {
                if (cnt[0] < cnt[1]) cout << "YES" << '\n';
                else cout << "NO" << '\n';
            }
        }
    }
    return 0;
}
// #include <bits/stdc++.h>
// #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// using namespace std;
// int main() {
//     IOS
//     int t;
//     cin >> t;
//     while (t --) {
//         int query;
//         priority_queue<int, vector<int>, greater<int> > s;
//         priority_queue<int, vector<int>, less<int> > t;
//         s.push(1), t.push(1);
//         cin >> query;
//         while (query --) {
//             int d, k;
//             string x;
//             cin >> d >> k >> x;
//             if (d == 1) {
//                 for (int i = 0; i < k; i ++)
//                     for (int j = 0; j < x.size(); j ++)
//                         s.push(x[j] - 'a' + 1);
//             } else {
//                 for (int i = 0; i < k; i ++)
//                     for (int j = 0; j < x.size(); j ++)
//                         t.push(x[j] - 'a' + 1);
//             }
//             if (t.top() > s.top()) cout << "YES" << '\n';
//             else if (t.top() < s.top()) cout << "NO" << '\n';
//             else {
//                 if (t.size() < s.size()) cout << "NO" << '\n';
//                 else {
//                     while (s.top() == t.top() && s.size() && t.size())
//                         s.pop(), t.pop();
//                     if (!s.size() && !t.size()) cout << "NO" << '\n';
//                     else if (!s.size()) cout << "YES" << '\n';
//                     else if (!t.size()) cout << "NO" << '\n';
//                     else cout << "NO" << '\n';
//                 }
//             }
//         }
//     }
//     return 0;
// }