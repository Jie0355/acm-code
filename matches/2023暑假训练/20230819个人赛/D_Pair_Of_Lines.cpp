#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define random(a, b) ((a) + rand() % ((b) - (a) + 1))

constexpr int M = 1e5 + 10;

struct node {
    i64 x, y;
} points[M];

i64 n, x[5], y[5];
bool is1, is2;

bool isInline(int now, int idx) {
    int idx1, idx2;
    if (now == 1) idx1 = 1, idx2 = 2;
    else idx1 = 3, idx2 = 4;
    if ((x[idx2] - x[idx1]) * (points[idx].y - y[idx1]) == (y[idx2] - y[idx1]) * (points[idx].x - x[idx1])) return true;
    return false;
}

bool check(int idx1, int idx2) {
    x[1] = points[idx1].x, y[1] = points[idx1].y;
    x[2] = points[idx2].x, y[2] = points[idx2].y;
    is1 = is2 = false;
    for (int i = 1; i <= n; i++) {
        if (i == idx1 || i == idx2) continue;
        else if (isInline(1, i)) continue;
        else if (!is1) {
            x[3] = points[i].x;
            y[3] = points[i].y;
            is1 = true;
        } else if (!is2) {
            x[4] = points[i].x;
            y[4] = points[i].y;
            is2 = true;
        } else if (isInline(2, i)) continue;
        else return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> points[i].x >> points[i].y;

    if (n <= 4) cout << "YES" << '\n';
    else {
        int start = random(1, n - 2);
        if (check(start, start + 1) || check(start + 1, start + 2) || check(start, start + 2)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}