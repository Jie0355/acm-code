#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    // bitset::operator[]

    bitset<4> foo1;

    foo1[1] = 1;       // 0010
    foo1[2] = foo1[1]; // 0110

    cout << "foo1: " << foo1 << '\n';

    // bitset::count

    bitset<8> foo2(string("10110011"));

    cout << foo2 << " has ";
    cout << foo2.count() << " ones and ";
    cout << (foo2.size() - foo2.count()) << " zeros.\n";

    // bitset::any
    
    bitset<16> foo3(string("10110"));

    if (foo3.any())
        cout << foo3 << " has " << foo3.count() << " bits set.\n";
    else
        cout << foo3 << " has no bits set.\n";

    // bitset::none

    bitset<16> foo4(string("11010111"));

    if (foo4.none())
        cout << foo4 << " has no bits set.\n";
    else
        cout << foo4 << " has " << foo4.count() << " bits set.\n";

    return 0;
}