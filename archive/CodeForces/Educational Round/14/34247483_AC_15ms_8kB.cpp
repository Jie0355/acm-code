#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int ans;
        cin >> ans;
        if (ans) cnt ++;
    }
    if (n == 1 && cnt == 1) printf("YES");
    else if (n == 1 && cnt == 0) printf("NO");
    else {
        if (cnt == n - 1) printf("YES");
        else printf("NO");
    }
    return 0;
}