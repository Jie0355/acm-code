#include <iostream>
using namespace std;
const int N = 2010;
int main() {
    int n = 0, wi[N];
    int dp_sum[N], dp_cnt[N];
    while (scanf("%d", &wi[n]) != EOF) {n ++;}
    int sum = 1, cnt = 1;
    for (int i = 0; i < n; i ++) {
        dp_sum[i] = 1; dp_cnt[i] = 1;
        for (int j = 0; j < i; j ++) {
            if (wi[i] <= wi[j]) dp_sum[i] = max(dp_sum[i], dp_sum[j] + 1);
            if (wi[i] > wi[j]) dp_cnt[i] = max(dp_cnt[i], dp_cnt[j] + 1);
        }
        sum = max(sum, dp_sum[i]);
        cnt = max(cnt, dp_cnt[i]);
    }
    cout << sum << endl << cnt;
    return 0;
}