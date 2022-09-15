//Title: L2 - 041
//Date: 2022-07-04 18:46
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m, k;
queue<int> pusher;
stack<int> box;
int main() {
    IOS;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        pusher.push(x);
    }
    // whole process
    while (1) {
        int overflow = 0;
        vector<int> pine;
        // every pine branches process
        while (1) {
            if (pine.empty()) {
                if (!box.empty()) {
                    pine.push_back(box.top());
                    box.pop();
                }
                else if (!pusher.empty()) {
                    pine.push_back(pusher.front());
                    pusher.pop();
                }
                else break; // box and pusher are empty
            }
            else {
                if (!box.empty() && box.top() <= pine.back()) {
                    pine.push_back(box.top());
                    box.pop();
                }
                else {
                    while (!pusher.empty() && box.size() <= m) {
                        if (pusher.front() <= pine.back()) {
                            pine.push_back(pusher.front());
                            pusher.pop();
                            break;
                        }
                        else {
                            if (box.size() == m) {
                                overflow = 1;
                                break;
                            }
                            else {
                                box.push(pusher.front());
                                pusher.pop();
                            }
                        }
                    }
                }
                if (pusher.empty())
                    if (box.empty() || box.top() > pine.back()) break;
            }
            if (pine.size() == k || overflow) break;
        }
        for (int i = 0; i < pine.size(); i ++) printf(" %d"+!i, pine[i]);
        printf("\n");
        if (pusher.empty() && box.empty()) break;
    }
    return 0;
}