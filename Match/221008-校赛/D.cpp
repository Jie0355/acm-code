#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
LL GetNum(LL f, LL s, int l) {
    LL t = 0;
    for (int i = 0; i < l; i ++) {
        if (i & 1) t = t * 10 + s;
        else t = t * 10 + f;
    }
    return t;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        vector<LL> v;
        LL l, r, w;
        cin >> l >> r >> w;
        LL tl = l, tr = r;
        int digl = 0, digh = 0;
        while (tl) {tl /= 10; digl ++;}
        while (tr) {tr /= 10; digh ++;}
        for (int i = max(2, digl); i <= digh; i ++) {
            for (LL j = 0; j <= 9; j ++) {
                LL x = (w ^ j);
                if (x > 0 && x < 10) {
                    LL xx = GetNum(x, j, i);
                    if (xx >= l && xx <= r) v.push_back(xx);
                }
            }
        }
        cout << v.size() << endl;
    }
    return 0;
}