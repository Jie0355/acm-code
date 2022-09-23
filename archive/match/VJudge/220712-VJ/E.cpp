#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int Mi = 1e3 + 10, Mj = 2e6 + 10;
bool prime[Mj];
void sievePrime() {
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int i = 2; i <= sqrt(Mj); i++)
        if (prime[i])
            for (int j = i * i; j <= Mj; j += i)
                prime[j] = false;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}
int main() {
    IOS; sievePrime();
    int n, cnt, k = 0;
    int arr[Mi], unCnt[Mi] = {0};
    bool join[Mi * 1000], exist[Mi];
    vector<int> unArr[Mi];
    vector<pair<int, int>> iun;
    cin >> n;
    memset(join, false, sizeof(join));
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if (!join[x] || x == 1) {
            arr[k ++] = x;
            join[x] = true;
        }
    }
    cnt = k;
    for (int i = 0; i < k; i ++) {
        for (int j = 0; j < k; j ++) {
            if (i == j) continue;
            if (!prime[arr[i] + arr[j]]) {
                unArr[i].push_back(j);
                unCnt[i] ++;
            }
        }
    }
    for (int i = 0; i < k; i ++) iun.push_back({i, unCnt[i]});
    // for (int i = 0; i < iun.size(); i ++)
    //     printf("{%d, %d} ", iun[i].first, iun[i].second);
    memset(exist, true, sizeof(exist));
    while (!iun.empty()) {
        sort(iun.begin(), iun.end(), cmp);
        auto now = iun[0];
        iun.erase(iun.begin(), iun.begin() + 1);
        if (now.second != unCnt[now.first]) continue;
        if (now.second == 0) break;
        exist[now.first] = false;
        cnt --;
        for (int i = 0; i < unArr[now.first].size(); i ++) {
            if (!exist[unArr[now.first][i]]) continue;
            unCnt[unArr[now.first][i]] --;
            iun.push_back({unArr[now.first][i], unCnt[unArr[now.first][i]]});
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < k; i ++)
        if (exist[i]) cout << arr[i] << ' ';
    return 0;
}