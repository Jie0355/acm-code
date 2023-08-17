#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int M = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    i64 arr[M];
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + n + 1);

    i64 sum[M] = {0};
    for (int i = 1; i <= n; i ++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    if (n % 3 != 0) {
        cout << "No" << '\n';
    } else {
        int div = n / 3;
        i64 x = sum[1 * div] - sum[0 * div];
        i64 y = sum[2 * div] - sum[1 * div];
        i64 z = sum[3 * div] - sum[2 * div];
        if (x == z) {
            cout << "No" << '\n';
        } else {
            bool is = false;
            if (x == y) {
                i64 t = z - x;
                for (int i = 1; i <= 2 * div; i ++) {
                    for (int j = 2 * div + 1; j <= 3 * div; j ++) {
                        if (arr[j] != arr[i] && arr[j] - arr[i] != t) {
                            swap(arr[j], arr[i]);
                            is = true;
                            break;
                        }
                    }
                    if (is) break;
                }
            } else if (y == z) {
                i64 t = z - x;
                for (int i = div + 1; i <= 3 * div; i ++) {
                    for (int j = 1; j <= div; j ++) {
                        if (arr[j] != arr[i] && arr[i] - arr[j] != t) {
                            swap(arr[j], arr[i]);
                            is = true;
                            break;
                        }
                    }
                    if (is) break;
                }
            } else is = true;
            if (is == true) {
                cout << "Yes" << '\n';
                for (int i = 1; i <= n; i ++) {
                    cout << arr[i];
                    if (i % div == 0) cout << '\n';
                    else cout << " ";
                }
            } else cout << "No";
        }
    }

    return 0;
}