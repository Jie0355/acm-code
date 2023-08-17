#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define random(a, b) ((a) + rand() % ((b) - (a) + 1))

stringstream ss;

void solve() {
    int n;
    n = random(1, 18);
    cout << n << '\n';
    int m = pow(2, n) - 1;
    vector<int> v;
    for (int i = 0; i < m; i ++) {
        int x = random(0, 100);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i ++) {
        cout << v[i] << " \n"[i == m - 1];
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int randseed = time(NULL);
    if (argc > 1) {
        ss.clear();
        ss << argv[1];
        ss >> randseed;
    }
    srand(randseed);

    int t = 1;
    // cin >> t;
    cout << t << '\n';

    while (t--) {
        solve();
    }

    return 0;
}
