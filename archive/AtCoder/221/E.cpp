#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int M = 1e5 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

int cmp(int a, int b) {
    return a > b;
}

int main() {
    IOS;
    int arr[15], A = 0, B = 0;
    char str[15];
    cin >> str;
    for (int i = 0; str[i]; i ++) arr[i] = str[i] - '0';
    sort(arr, arr + strlen(str), cmp);
    A = arr[0]; B = arr[1];
    for (int i = 2; i < strlen(str); i ++) {
        if (A < B) A = A * 10 + arr[i];
        else B = B * 10 + arr[i];
    }
    cout << A * B;
    return 0;
}
