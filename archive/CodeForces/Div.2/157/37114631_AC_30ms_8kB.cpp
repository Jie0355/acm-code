//Title: B
//Date: 2022-07-12 13:33
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    IOS;
    int arr[10];
    for (int i = 1; i <= 9; i ++) cin >> arr[i];
    arr[1] = (arr[6] + arr[8]) / 2;
    arr[9] = arr[4] + (arr[6] - arr[8]) / 2;
    arr[5] = arr[2] + arr[3] - arr[9];
    for (int i = 1; i <= 9; i ++) {
        cout << arr[i];
        if (!(i % 3)) cout << endl;
        else cout << ' ';
    }
    return 0;
}