#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int M = 1e5 + 10;
struct node {
    ll locate, tall;
}tree[M];
int main() {
    IOS;
    int n, cnt = 0;
    ll nowl;
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> tree[i].locate >> tree[i].tall;
    for (int i = 0; i < n; i ++) {
        // the first and the last tree
        if (!i || i == n - 1) {
            cnt ++;
            nowl = tree[i].locate;
            continue;
        }
        // fall to the right
        if (tree[i].locate - tree[i].tall > nowl) {
            cnt ++;
            nowl = tree[i].locate;
            continue;
        }
        // fall to the left
        if (tree[i].locate + tree[i].tall < tree[i + 1].locate) {
            cnt ++;
            nowl = tree[i].locate + tree[i].tall;
            continue;
        }
        nowl = tree[i].locate;
    }
    cout << cnt;
    return 0;
}