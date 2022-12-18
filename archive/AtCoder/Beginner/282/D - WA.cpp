#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int M = 2e5 + 10;
int n, m;
int h[2 * M], e[2 * M], ne[2 * M], idx = 0;
void add(int a, int b) {
    e[idx] = b;
	ne[idx] = h[a], h[a] = idx;
	idx ++;
}
int main() {
    IOS
	memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m --) {
        int a, b;
        cin >> a >> b;
        add(a, b); add(b, a);
    }
    int now, color[M];
    bool vis[M];
    queue<int> iq;
    for (int i = 1; i <= n; i ++) {
        vis[i] = false;
        color[i] = -1;
    }
    iq.push(1); color[1] = 1;
    while (iq.size()) {
        int x = iq.front(); iq.pop();
        vis[x] = true;
        now = 1 - color[x];
        for (int i = h[x]; ~i; i = ne[i]) {
            int k = e[i];
            if (!vis[k]) {
                iq.push(k);
                if (color[k] == -1) color[k] = now;
                else if (color[k] != now) {
                    cout << 0 << '\n';
                    return 0;
                }
            }
        }
    }
    // for (int i = 1; i <= n; i ++) cout << color[i] << " ";
    set<pair<int, int>> is;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) vis[j] = false;
        for (int j = h[i]; ~j; j = ne[j]) {
            int k = e[j];
            vis[k] = true;
        }
        for (int j = 1; j <= n; j ++) {
            if (!vis[j] && color[i] != color[j]) {
                if (i < j) is.insert({i, j});
                else is.insert({j, i});
            }
        }
    }
    cout << is.size() << '\n';
    return 0;
}