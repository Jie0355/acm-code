//Title: A
//Date: 2022-07-08 13:02
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int main() {
    IOS;
    ll a, b, s;
    cin >> a >> b >> s;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (s < a + b) {
        if (!a && !b && !(s % 2)) cout << "Yes";
        else cout << "No";
    }
    else {
        if (!((s - (a + b)) % 2)) cout << "Yes";
        else cout << "No";
    }
    return 0;
}