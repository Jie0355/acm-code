#include <iostream>
#include <vector>
#include "Algorithm.hpp"
using namespace std;
using namespace Algorithm;
int main() {
    vector<int> v1(5, 1);
    int ans = 0;
    cout << accumulate(v1.begin(), v1.end(), ans) << '\n';
    vector<int> v2(5);
    vector<int>::iterator it = partial_sum(v1.begin(), v1.end(), v2.begin(), &ans);
    cout << *it << '\n';
    it = max_element(v2.begin(), v2.end());
    cout << *it << '\n';
    it = min_element(v2.begin(), v2.end());
    cout << *it << '\n';
    ans = count(v1.begin(), v1.end(), 1);
    cout << ans << '\n';
    it = find(v2.begin(), v2.end(), 3);
    cout << *it << '\n';
    for (it = v2.begin(); it != v2.end(); ++ it) cout << *it << " ";
    cout << '\n';
    reverse(v2.begin(), v2.end());
    for (it = v2.begin(); it != v2.end(); ++ it) cout << *it << " ";
    cout << '\n';
    quick_sort(v2.begin(), v2.end());
    for (it = v2.begin(); it != v2.end(); ++ it) cout << *it << " ";
    cout << '\n';
    return 0;
}