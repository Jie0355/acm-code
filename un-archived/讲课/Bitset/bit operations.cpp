#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    // bitset::set

    bitset<4> foo1;

    cout << foo1.set() << '\n';     // 1111
    cout << foo1.set(2, 0) << '\n'; // 1011
    cout << foo1.set(2) << '\n';    // 1111
    cout << '\n';
    
    // bitset::reset

    bitset<4> foo2(string("1011"));

    cout << foo2.reset(1) << '\n'; // 1001
    cout << foo2.reset() << '\n';  // 0000
    cout << '\n';

    // bitset::flip

    bitset<4> foo3(string("0001"));

    cout << foo3.flip(2) << '\n'; // 0101
    cout << foo3.flip() << '\n';  // 1010

    return 0;
}