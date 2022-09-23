#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int M = 1e5 + 10;
int color = 0, inv[M] = {0}, cole[M];
vector<pair<int, int>> v[M];
void DFS(int nowv, int formerv, int nowColor) {
    for (int i = 0; i < v[nowv].size(); i ++) {
        auto info = v[nowv][i];
        if (info.first == formerv) continue;
        nowColor ++;
        if (nowColor > color) nowColor = 1;
        cole[info.second] = nowColor;
        //nowColor = (nowColor + 1) % color;
        DFS(info.first, nowv, nowColor);
    }
}
int main() {
    IOS;
    int n, root;
    cin >> n;
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back({b, i});
        v[b].push_back({a, i});
        inv[a] ++; inv[b] ++;
    }
    for (int i = 1; i <= n; i ++) {
        if (inv[i] > color) {
            color = inv[i];
            root = i;
        }
    }
    DFS(root, -1, 0);
    cout << color << endl;
    for (int i = 0; i < n - 1; i ++)
        cout << cole[i] << endl;
    return 0;
}