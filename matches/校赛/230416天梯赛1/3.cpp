#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sumA, sumB;
    cin >> sumA >> sumB;
    int ori_A = sumA, ori_B = sumB;

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        int Aplus, Asum, Bplsu, Bsum;
        cin >> Aplus >> Asum >> Bplsu >> Bsum;
        int sum = Aplus + Bplsu;
        if (Asum == Bsum) continue;
        else {
            if (Asum == sum) sumA --;
            else if (Bsum == sum) sumB --;
        }
        if (sumA < 0) {
            cout << "A" << '\n';
            cout << ori_B - sumB << '\n';
            return 0;
        } else if (sumB < 0) {
            cout << "B" << '\n';
            cout << ori_A - sumA << '\n';
            return 0;
        }
    }

    return 0;
}