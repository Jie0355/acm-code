#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int attrR = 0;
    int endx = str.size() - 1;
    for (; endx >= 0; endx --) {
        if (str[endx] == '(') attrR ++;
        else if (str[endx] == ')') attrR --;
        else if (str[endx] == '#') break;
        if (attrR > 0) {
            cout << -1 << '\n';
            return 0;
        }
    }
    attrR *= -1;

    int attrL = 0, cnt = 0;
    for (int i = 0; i < endx; i ++) {
        if (str[i] == '(') attrL ++;
        else if (str[i] == ')') attrL --;
        else if (str[i] == '#') {
            attrL --;
            cnt ++;
        }
        if (attrL < 0) {
            cout << -1 << '\n';
            return 0;
        }
    }

    int ans;
    if (attrL > attrR) {
        ans = attrL - attrR;
    } else {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < cnt; i ++) cout << 1 << '\n';
    cout << ans << '\n';

    return 0;
}