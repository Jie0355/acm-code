//795.前缀和
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int main() {
    int n,  m;
    int a[N], s[N] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
    while (m --) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
}

//796.子矩阵的和
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N], s[N][N];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
    while (q --) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
        printf("%d\n", sum);
    }
    return 0;
}

//797.差分
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) insert(i, i, a[i]);
    while (m --) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        insert(l, r, c);
    }
    for (int i = 1; i <= n; i ++) b[i] += b[i - 1];
    for (int i = 1; i <= n; i ++) printf("%d ", b[i]);
    return 0;
}

//798.差分矩阵
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            insert(i, j, i, j, a[i][j]);
    while (q --) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            b[i][j] += b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) printf("%d ", b[i][j]);
        puts(" ");
    }
    return 0;
}