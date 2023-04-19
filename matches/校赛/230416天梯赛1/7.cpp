#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int cnt[5] = {0}; // GPLT
    for (auto xi : s) {
        if (xi == 'G' || xi == 'g') cnt[1] ++;
        else if (xi == 'P' || xi == 'p') cnt[2] ++;
        else if (xi == 'L' || xi == 'l') cnt[3] ++;
        else if (xi == 'T' || xi == 't') cnt[4] ++;
    }

    // for (int k = 1; k <= 4; k ++) {
    //     cout << cnt[k] << " ";
    // }
    // cout << '\n';

    int i = 1;
    bool is = true;
    while (is) {
        is = false;
        for (int k = 1; k <= 4; k ++) {
            if (cnt[k] > 0) {
                is = true;
                break;
            }
        }
        if (!is) break;
        while (cnt[i] <= 0) {
            i ++;
            if (i == 5) i = 1;
        }
        cnt[i] --;
        if (i == 1) cout << 'G';
        else if (i == 2) cout << 'P';
        else if (i == 3) cout << 'L';
        else if (i == 4) cout << 'T';
        i ++;
        if (i == 5) i = 1;
    }

    return 0;
}