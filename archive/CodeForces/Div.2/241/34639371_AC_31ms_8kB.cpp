//A
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;

int main() {
    IOS;
    int n, lowlimit = -INF, uplimit = INF;
    int limNum;
    char sign[5], ans;
    cin >> n;
    while (n --) {
        cin >> sign;
        if (!strcmp(sign, ">")) {
            cin >> limNum >> ans;
            if (ans == 'Y') {
                if (lowlimit < limNum + 1) lowlimit = limNum + 1;
            }
            else {
                if (uplimit > limNum) uplimit = limNum;
            }
        }
        else if (!strcmp(sign, ">=")) {
            cin >> limNum >> ans;
            if (ans == 'Y') {
                if (lowlimit < limNum) lowlimit = limNum;
            }
            else {
                if (uplimit > limNum - 1) uplimit = limNum - 1;
            }
        }
        else if (!strcmp(sign, "<")) {
            cin >> limNum >> ans;
            if (ans == 'Y') {
                if (uplimit > limNum - 1) uplimit = limNum - 1;
            }
            else {
                if (lowlimit < limNum) lowlimit = limNum;
            }
        }
        else if (!strcmp(sign, "<=")) {
            cin >> limNum >> ans;
            if (ans == 'Y') {
                if (uplimit > limNum) uplimit = limNum;
            }
            else {
                if (lowlimit < limNum + 1) lowlimit = limNum + 1;
            }
        }
    }
    // cout << limNum << endl;
    // cout << lowlimit << " " << uplimit << endl;
    if (lowlimit != -INF && uplimit >= lowlimit) cout << lowlimit;
    else if (lowlimit == -INF && uplimit != INF) cout << lowlimit;
    else cout << "Impossible";
    return 0;
}