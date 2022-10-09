#include <iostream>
using namespace std;
const int M = 110;
int main() {
    int n, arr[M];
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];

    }
    for (int i = 0; i < n; i ++) {
        if (i > n - 3) cout << (arr[j] - arr[j - 1]) * (arr[j] - arr[j - 1]);
        long long ans = 0;
        arr[i + 2] = arr[0];
        for (int j = i + 3; j < n; j ++) {
            ans += (arr[j] - arr[j - 1]) * (arr[j] - arr[j - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}