#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long atoin(long long f, long long s, int l) {
    long long t = 0;
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
        vector<long long> v;
        long long l, r, w, cnt = 0;
        cin >> l >> r >> w;
        long long tl = l, tr = r;
        int cntl = 0, cntr = 0;
        while (tl) {tl /= 10; cntl ++;}
        while (tr) {tr /= 10; cntr ++;}
        for (int i = cntl; i <= cntr; i ++) {
            if (i == 1 || !i) continue;
            else if (i == 2) {
                long long ll = max((long long)10, l), rr = min((long long)99, r);
                for (long long j = ll; j <= rr; j ++) {
                    long long x = j / 10, y = j % 10;
                    if ((x ^ y) == w) v.push_back(j);
                }
            } else {
                for (long long j = 0; j <= 9; j ++) {
                    long long x = (w ^ j);
                    if (x > 0 && x < 10) {
                        long long xx = atoin(x, j, i);
                        if (xx >= l && xx <= r) v.push_back(xx);
                    }
                }
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        cout << v.size() << endl;
        // for (int i = 0; i < v.size(); i ++) cout << v[i] << " ";
    }
}