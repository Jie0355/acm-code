//835.Trie字符串统计
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

// @description: Trie
const int M = 1e5 + 10; // Length of Sting

int cnt[M], tot = 0;
struct Node {
    int next[26 + 1];
}Trie[M];

void insert(string s) {
    int now = 0;
    for (int i = 0; i < s.size(); i ++) {
        int x = s[i] - 'a';
        if (!Trie[now].next[x]) {
            tot ++;
            Trie[now].next[x] = tot;
        }
        now = Trie[now].next[x];
    }
    cnt[now] ++;
}

int query(string s) {
    int now = 0;
    for (int i = 0; i < s.size(); i ++) {
        int x = s[i] -  'a';
        if (!Trie[now].next[x]) {
            return 0;
        }
        now = Trie[now].next[x];
    }
    return cnt[now];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        char op;
        string s;
        cin >> op >> s;
        // cout << op << " " << s << '\n';
        if (op == 'I') insert(s);
        else cout << query(s) << '\n';
    }

    return 0;
}
