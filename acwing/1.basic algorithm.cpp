/*
*
*   第一讲《基础算法》
*
*/

//875.快速排序
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6+10;

int q[MAX_N], n;

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}

//876.快速排序实现第K个数
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;

int n, k;
int q[MAX_N];

int quick_sort(int l, int r, int k) {
    if (l == r) return q[l];
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i ++; while (q[i] < x);
        do j --; while (q[j] > x);
        if (i < j) swap(q[i],q[j]);
    }
    int sl = j - l + 1;
    if(k <= sl) return quick_sort(l, j, k);
    return quick_sort(j + 1, r, k - sl);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    printf("%d", quick_sort(0, n-1, k));
    return 0;
}

//787.归并排序
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+10;

int q[MAX_N], temp[MAX_N], n;

void merge_sort(int q[], int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(q[i] <= q[j]) temp[k ++] = q[i ++];
        else temp[k ++] = q[j ++];
    }
    while(i <= mid) temp[k ++] = q[i ++];
    while(j <= r) temp[k ++] = q[j ++];
    for(i = l, j = 0; i <= r; i ++, j ++) q[i] = temp[j];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i ++) printf("%d ", q[i]);
    return 0;
}

//788.逆序对的数量
/*
存在正整数 i, j 使得 1 ≤ i < j ≤ n 而且 A[i] > A[j]
则 <A[i], A[j]> 这个有序对称为 A 的一个逆序对
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5+10;

int q[MAX_N], temp[MAX_N], n;

LL merge_sort(int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);
    int i = l,j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) temp[k ++] = q[i ++];
        else {
            temp[k ++] = q[j ++];
            res += mid - i + 1;
        }
    }
    while (i <= mid) temp[k ++] = q[i ++];
    while (j <= r) temp[k ++] = q[j ++];
    for (int i = l, j = 0; i <= r; i ++, j ++) q[i] = temp[j];
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    printf("%lld", merge_sort(0, n - 1));
    return 0;
}

//789.数的范围
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    while (m --) {
        int x, l = 0, r = n - 1;
        scanf("%d", &x);
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if (a[l] != x) printf("-1 -1\n");
        else {
            printf("%d ", l);
            l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (a[mid] <= x) l = mid;
                else r = mid - 1;
            }
            printf("%d\n", l);
        }
    }
    return 0;
}

//790.数的三次方根
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double num;
    scanf("%lf", &num);
    double l = -10000, r = 10000;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= num) r = mid;
        else l = mid;
    }
    printf("%.6lf", l);
    return 0;
}

//791.高精度加法
#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;
    if (A.size() < B.size()) return add(B, A);
    int t = 0;
    for (int i = 0; i < A.size(); i ++) {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(1);
    return C;
}

int main() {
    string a, b;
    vector<int> A,B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    vector<int> C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    return 0;
}

//782.高精度减法
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 10;

bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i --)
        if (A[i] != B[i])
            return A[i] > B[i];
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i ++) {
        t = A[i] - t;
        if (i < B.size()) t-= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;   //两数相差为负 向前一位借位 t --> 1
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    if (cmp(A, B)) {    //A >= B 输出第一种情况 即 A - B
        vector<int> C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    }
    else {
        vector<int> C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    }
    return 0;
}

//793.高精度乘法
#include <bits/stdc++.h>
using namespace std;
vector<int> mul(vector<int> &A, int &B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i ++) {  //t 不为 0 且为最后一次输入时应 t --> C
        if (i < A.size()) t += A[i] * B;
        C.push_back(t % 10);
        t /= 10;
    }
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a;
    int B;
    vector<int> A;
    cin >> a >> B;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    vector<int> C = mul(A, B);
    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    return 0;
}

//794.高精度除法
#include <bits/stdc++.h>
using namespace std;

vector<int> mul(vector<int> &A, int &B, int &t) {
   vector<int> C;
   t = 0;
   for (int i = A.size() - 1; i >= 0; i --) {   //i 从最后一位 (原数最高位) 开始递减
        t = t * 10 + A[i];
        C.push_back(t / B);
        t %= B;
    }
   reverse(C.begin(), C.end()); //向量 C 中存入的为正序答案 为与其它三则运算保持一致性 故转置
   while(C.size() > 1 && C.back() == 0) C.pop_back();
   return C;
}

int main() {
    string a;
    int B, t;
    vector<int> A;
    cin >> a >> B;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    vector<int> C = mul(A, B, t);
    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    printf("\n%d", t);
    return 0;
}

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

//799.最长连续不重复子序列
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], s[N];

int main() {
    int n, res = 0;
    cin >> n;
    for (int i = 0; i < n; i ++) scanf("%d", a + i);
    for (int i = 0, j = 0; i < n; i ++) {
        s[a[i]] ++;
        while (s[a[i]] > 1) {
            s[a[j]] --;
            j ++;
        }
        res = max(res, i - j + 1);
    }
    cout << res;
    return 0;
}

//800.数组元素的目标和
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int main() {
    int n, m, ans;
    int a[N], b[N];
    cin >> n >> m >> ans;
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i ++) scanf("%d", &b[i]);
    for (int i = 0, j = m - 1; i < n; i ++) {
        while (j >= 0 && a[i] + b[j]> ans) j --;
        if (a[i] + b[j] == ans) {
            printf("%d %d\n", i, j);
            break;
        }
    }
    return 0;
}

//2816.判断子序列
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int main() {
    int n, m;
    int a[N], b[N];
    cin >> n >> m;
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i ++) scanf("%d", &b[i]);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) i ++;
        j ++;
    }
    if (i == n) printf("Yes");
    else printf("No");
    return 0;
}

//801.二进制中1的个数
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n --) {
        int x, sum = 0;
        scanf("%d", &x);
        for (int i = x; i; i -= i & -i) sum ++;
        printf("%d ", sum);
    }
    return 0;
}

//802.离散化
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 3e5 + 10;

int a[N] = {0}, s[N] = {0};
vector<int> alls;   //存储即将使用的数轴点
vector<PII> add, query;

//返回数轴上的点{x}在序列中的位置
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i= 0; i < n; i ++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    //去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    //离散化
    for (auto item : add) {
        int x = find(item.first);   //寻找数轴值在离散化后序列中的位置
        a[x] += item.second;    //相应位置插入值
    }
    //预处理前缀和
    for (int i = 1; i <= alls.size(); i ++) s[i] = s[i - 1] + a[i];
    for (auto item : query) {
        //获得数轴上的询问数对{l, r}离散化后的值
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}

//803.区间合并
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

void merge(vector<PII> &segs) {
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg : segs) {
        if (ed < seg.first) {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);
    }
    if (st != -2e9) res.push_back({st, ed});
    segs = res;
}

int main() {
    int n;
    vector<PII> segs;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int l, r;
        scanf("%d %d", &l, &r);
        segs.push_back({l, r});
    }
    merge(segs);
    printf("%d", segs.size());
    return 0;
}