#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int M = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int price[M] = {0};
    for (int i = 1; i <= n; i++) cin >> price[i];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> color1, color2, color3;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x == 1) color1.push({price[i], i});
        else if (x == 2) color2.push({price[i], i});
        else color3.push({price[i], i});
    }
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x == 1) color1.push({price[i], i});
        else if (x == 2) color2.push({price[i], i});
        else color3.push({price[i], i});
    }

    int query;
    cin >> query;

    int buyed[M] = {0};
    while (query--) {
        int needs;
        cin >> needs;
        if (needs == 1) {
            if (color1.empty()) cout << -1 << " ";
            else {
                auto xi = color1.top();
                color1.pop();
                while (!color1.empty() && buyed[xi.second]) {
                    xi = color1.top();
                    color1.pop();
                }
                if (buyed[xi.second]) cout << -1 << " ";
                else {
                    cout << xi.first << " ";
                    buyed[xi.second] = 1;
                }
            }
        } else if (needs == 2) {
            if (color2.empty()) cout << -1 << " ";
            else {
                auto xi = color2.top();
                color2.pop();
                while (!color2.empty() && buyed[xi.second]) {
                    xi = color2.top();
                    color2.pop();
                }
                if (buyed[xi.second]) cout << -1 << " ";
                else {
                    cout << xi.first << " ";
                    buyed[xi.second] = 1;
                }
            }
        } else {
            if (color3.empty()) cout << -1 << " ";
            else {
                auto xi = color3.top();
                color3.pop();
                while (!color3.empty() && buyed[xi.second]) {
                    xi = color3.top();
                    color3.pop();
                }
                if (buyed[xi.second]) cout << -1 << " ";
                else {
                    cout << xi.first << " ";
                    buyed[xi.second] = 1;
                }
            }
        }
    }

    return 0;
}