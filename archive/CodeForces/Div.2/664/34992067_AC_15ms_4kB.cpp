//B
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e5 + 7;
const int MOD = 1e9 + 7;

int check(int r, int g, int b, int w) {
    if (w & 1) {
        if (r % 2 == 1 && g % 2 == 1 && b % 2 == 1) return 1;
        else if (r % 2 == 0 && g % 2 == 0 && b % 2 == 0) return 1;
        else if (r % 2 == 1 && g % 2 == 1 && b % 2 == 0 && b > 0) return 1;
        else if (r % 2 == 1 && g % 2 == 0 && b % 2 == 1 && g > 0) return 1;
        else if (r % 2 == 0 && g % 2 == 1 && b % 2 == 1 && r > 0) return 1;
        else return 0;
    }
    else {
        if (r % 2 == 1 && g % 2 == 1 && b % 2 == 1) return 1;
        else if (r % 2 == 0 && g % 2 == 0 && b % 2 == 0) return 1;
        else if (r % 2 == 1 && g % 2 == 0 && b % 2 == 0) return 1;
        else if (r % 2 == 0 && g % 2 == 1 && b % 2 == 0) return 1;
        else if (r % 2 == 0 && g % 2 == 0 && b % 2 == 1) return 1;
        else return 0;
    }
}

int main() {
    IOS;
    int t;
    int rt, gt, bt, wt;
    cin >> t;
    while (t --) {
        cin >> rt >> gt >> bt >> wt;
        if (check(rt, gt, bt, wt)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}