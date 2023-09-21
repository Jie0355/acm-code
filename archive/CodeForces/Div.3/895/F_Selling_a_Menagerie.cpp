#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

int arr[M];
bool vis[M];
vector<int> ins(M);

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        ins[i] = 0;
        vis[i] = false;
    }

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        ins[arr[i]]++;
    }

    int v[M];
    for (int i = 1; i <= n; i++) cin >> v[i];

    queue<int> iq;
    for (int i = 1; i <= n; i++) {
        if (!ins[i]) iq.push(i);
    }

    vector<int> ans;
    while (!iq.empty()) {
        int xi = iq.front();
        iq.pop();
        ans.push_back(xi);
        vis[xi] = true;
        if (!(--ins[arr[xi]])) iq.push(arr[xi]);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++) {
        if (ins[i]) pq.push({v[i], i});
    }

    while (!pq.empty()) {
        auto xi = pq.top();
        int x = xi.second;
        pq.pop();
        if (vis[x]) continue;
        while (true) {
            x = arr[x];
            if (vis[x]) break;
            vis[x] = true;
            ans.push_back(x);
        }
    }

    for (auto x : ans) cout << x << ' ';
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}