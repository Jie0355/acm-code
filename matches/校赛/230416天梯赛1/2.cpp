#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int hrs, min;
    scanf("%d:%d", &hrs, &min);

    int sum = hrs * 60 + min;
    // cout << sum << '\n';

    int times = 0;
    if (!min) {
        if (hrs >= 13 && hrs <= 23) times = hrs - 12;
        else {
            printf("Only %02d:%02d.  Too early to Dang.", hrs, min);
            return 0;
        }
    } else {
        if (hrs >= 12 && hrs <= 23) times = hrs - 12 + 1;
        else {
            printf("Only %02d:%02d.  Too early to Dang.", hrs, min);
            return 0;
        }
    }
    for (int i = 0; i < times; i ++) cout << "Dang";

    return 0;
}