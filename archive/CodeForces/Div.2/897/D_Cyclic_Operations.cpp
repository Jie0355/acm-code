#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 2e5 + 10;

int arr[M];
int f[M];
int t[M];
int n, k;

int lowbit(int x) {
    return x & -x;
}

void add(int x) {
    while (x <= n) {
        t[x]++;
        x += lowbit(x);
    }
}

void diff(int x) {
    while (x <= n) {
        t[x]--;
        x += lowbit(x);
    }
}

i64 sum(int x) {
    i64 res = 0;
    while (x >= 1) {
        res += t[x];
        x -= lowbit(x);
    }
    return res;
}

void solve() {
    cin >> n >> k;

    bool is = true;

    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    for (int i = 0; i <= n; ++i) {
        t[i] = 0;
        f[i] = 0;
    }

    if (k == 1) {
        is = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                is = false;
                break;
            }
        }
        if (is) cout << "Yes" << '\n';
        else cout << "No" << '\n';
        return;
    } else {
        is = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] == i + 1) is = false;
        }
        if (!is) {
            cout << "No" << '\n';
            return;
        }
    }
    int cnt = 0;
    for (int i = 0; i < k; ++i) {
        int x = arr[i];
        f[x]++;
        if (f[x] == 1) {
            add(x);
        } else if (f[x] == 2) {
            cnt++;
        }
    }
    is = false;
    if (sum(k) == k && cnt == 0) { is = true; }
    for (int i = k; i < n; ++i) {
        int x = arr[i];
        f[x]++;
        if (f[x] == 1) {
            add(x);
        } else if (f[x] == 2) {
            cnt++;
        }
        int y = arr[i - k];
        f[y]--;
        if (f[y] == 1) {
            cnt--;
        } else if (f[y] == 0) {
            diff(y);
        }
        if (sum(i + 1) - sum(i - k) == k && cnt == 0) {
            is = true;
            break;
        }
    }
    if (is) {
        cout << "Yes" << '\n';
    } else cout << "No" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}