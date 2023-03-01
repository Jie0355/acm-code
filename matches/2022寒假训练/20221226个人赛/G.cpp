#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS
    int n, L;
    cin >> n >> L;
    int a[55], b[55];
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) cin >> b[i];
    vector<int> v1, v2;
    for (int i = 1; i < n; i ++) {
        v1.push_back(a[i] - a[i - 1]);
        v2.push_back(b[i] - b[i - 1]);
    }
    v1.push_back(L - a[n - 1] + a[0]);
    v2.push_back(L - b[n - 1] + b[0]);
    int sizev = v1.size();
    for (int i = 0; i < sizev; i ++) v1.push_back(v1[i]);
    bool is = false;
    for (int i = 0; i < v1.size(); i ++) {
        if (v1[i] == v2.front()) {
            int j;
            for (j = 1; j < v2.size(); j ++)
                if (v1[i + j] != v2[j]) break;
            if (j == v2.size()) {is = true; break;}
        }
    }
    if (is) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}