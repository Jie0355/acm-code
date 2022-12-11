#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int main() {
    int n;
    LL u, mmi = 0;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        LL ai, mi;
        cin >> ai >> mi;
        mmi = max(mmi, mi);
        if (!i) u = ai - mi;
        else u = __gcd(u, ai - mi);
    }
    // cout << u << '\n';
    vector<LL> v;
    for (int i = 1; i <= sqrt(u); i ++) {
        if (!(u % i)) {
            if (i > mmi) v.push_back(i);
            if (i != u / i && u / i > mmi) v.push_back(u / i);
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto vi : v) {
        cout << vi << '\n';
    }
    return 0;
}