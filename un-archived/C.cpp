#include <iostream>
#include <cmath>
using namespace std;
const int M = 1e5 + 110;
int n, arr[M];
int diff[M] = {0}, ldiff[M] = {0}, rdiff[M] = {0};
int main() {
    cin >> n;
    int max = 0, idx = 0;
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        if (i) diff[i] = arr[i] - arr[i - 1];
        if (fabs(diff[i]) > max) {max = fabs(diff[i]); idx = i;}
    }
    int sum = 0;    
    for (int i = 1; i < n; i ++) {
        if (i == idx) continue;
        sum += diff[i];
    }
    sum = sum / (n - 2);
    // left condition
    int ld = sum, lpre = 0, lans = 0;
    for (int i = 1; i < n; i ++) ldiff[i] = diff[i];
    for (int i = 1; i < n; i ++) {
        if (i == idx) {lpre = 0; continue;}
        int x = ld - ldiff[i];
        if (x > 0) {
            int t;
            if (lpre + x == 0) {lpre = 0; continue;}
            if (x & 1) t = (x + 1) / 2 + 1;
            else t = x / 2;
            lans += t;
            if (i != idx - 1 && i < n - 1) ldiff[i + 1] -= x;
        }
        else {
            if (lpre + x == 0) {lpre = 0; continue;}
            lans += fabs(x);
            if (i != idx - 1 && i < n - 1) ldiff[i + 1] += fabs(x);
        }
        lpre = x;
    }
    // right condition
    int rd = sum + 1, rpre = 0, rans = 0;
    for (int i = 1; i < n; i ++) rdiff[i] = diff[i];
    for (int i = 1; i < n; i ++) {
        if (i == idx) {rpre = 0; continue;}
        int x = rd - rdiff[i];
        if (x > 0) {
            int t;
            if (rpre + x == 0) {rpre = 0; continue;}
            if (x & 1) t = (x + 1) / 2 + 1;
            else t = x / 2;
            rans += t;
            if (i != idx - 1 && i < n - 1) rdiff[i + 1] -= x;
        }
        else {
            if (rpre + x == 0) {rpre = 0; continue;}
            rans += fabs(x);
            if (i != idx - 1 && i < n - 1) rdiff[i + 1] += fabs(x);
        }
        rpre = x;
    }
    // cout << lans << " " << rans << endl;
    int ans = min(lans, rans);
    cout << ans;
    return 0;
}