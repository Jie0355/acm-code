#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
__int128 read() {
    __int128 x = 0, np = 1;
    char c = getchar();
    while (!isdigit(c) && c != '-')
        c = getchar();
    if (c == '-') c = getchar(), np = -1;
    while (isdigit(c))
        x = x * 10 + (c - '0'), c = getchar();
    return x * np;
}
void write(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    IOS
    int t;
    cin >> t;
    while (t --) {
        __int128 a, b, c, d;
        a = read(); b = read();
        c = read(); d = read();
        write(a + b + c + d);
        cout << '\n';
    }
    return 0;
}