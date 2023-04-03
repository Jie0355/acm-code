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
            Trie[now].next[x] = tot;
            tot ++;
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