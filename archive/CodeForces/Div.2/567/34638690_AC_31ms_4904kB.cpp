//B
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e6 + 7;
const int MOD = 1e9 + 7;

int n, mid;
char str[M], num1[M], num2[M];
char sum1[M], sum2[M];

//等长比较
int cmpE(int mid) {
    for (int i = 0; i <= mid; i ++) {
        if (str[i] > str[i + mid]) return 0;
        else if (str[i] < str[i + mid]) return 1;
    }
    return 0;
}

//不等长比较
int cmpDE(char *n1, char *n2) {
    if (strlen(n1) > strlen(n2)) return 1;
    else if (strlen(n1) < strlen(n2)) return -1;
    for (int i = strlen(n1) - 1; i >= 0; i --) {
        if (n1[i] > n2[i]) return 1;
        else if (n1[i] < n2[2]) return -1;
    }
    return 0;
}

//高精度加法
void add(char *n1, char *n2, char *s1) {
    int len1 = strlen(n1), len2 = strlen(n2);
    int t = 0, temp;
    for (int i = 0; i < len1 / 2; i ++) {
        temp = n1[i];
        n1[i] = n1[len1 - i - 1];
        n1[len1 - i - 1] = temp;
    }
    for (int i = 0; i < len2 / 2; i ++) {
        temp = n2[i];
        n2[i] = n2[len2 - i - 1];
        n2[len2 - i - 1] = temp;
    }
    int i;
    for (i = 0; i < len1 && i < len2; i ++) {
        s1[i] = (n1[i] - '0' + n2[i] - '0' + t) % 10 + '0';
        t = (n1[i] - '0' + n2[i] - '0' + t) / 10;
    }
    while (i < len1) {
        s1[i] = (n1[i] - '0' + t) % 10 + '0';
        t = (n1[i] - '0' + t) / 10;
        i ++;
    }
    while (i < len2) {
        s1[i] = (n2[i] - '0' + t) % 10 + '0';
        t = (n2[i] - '0' + t) / 10;
        i ++;
    }
    while (t) {
        s1[i ++] = t + '0';
        t /= 10;
    }
}

int main() {
    IOS;
    cin >> n >> str;
    //type1
    mid = n / 2;
    while (str[mid] == '0' && mid < n) mid ++;
    if (mid == n / 2 && n & 1) {
        //Later_Bigger
        if (cmpE(mid)) {
            if (str[mid + 1] != '0') mid ++;
        }
    }
    int k = 0;
    for (int i = 0; i < mid; i ++) num1[i] = str[i];
    for (int i = mid; i < n; i ++) num2[k ++] = str[i];
    add(num1, num2, sum1);
    //type2
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    mid = n / 2;
    while (str[mid] == '0' && mid >= 0) mid --;
    if (mid == n / 2 && n & 1) {
        //Later_Bigger
        if (cmpE(mid)) {
            if (str[mid + 1] != '0') mid ++;
        }
    }
    k = 0;
    for (int i = 0; i < mid; i ++) num1[i] = str[i];
    for (int i = mid; i < n; i ++) num2[k ++] = str[i];
    add(num1, num2, sum2);
    if (cmpDE(sum1, sum2) == -1) {
        for (int i = strlen(sum1) - 1; i >= 0; i --) cout << sum1[i];
    }
    else for (int i = strlen(sum2) - 1; i >= 0; i --) cout << sum2[i];
    return 0;
}