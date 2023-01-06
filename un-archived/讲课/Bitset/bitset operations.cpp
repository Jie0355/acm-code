#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    // bitset::to_string

    bitset<4> foo1; // foo: 0000
    foo1.set();     // foo: 1111

    cout << foo1 << " as an string is: " << foo1.to_string() << '\n';

    // bitset::to_ulong

    bitset<4> foo2; // foo: 0000
    foo2.set();     // foo: 1111

    cout << foo2 << " as an integer is: " << foo2.to_ulong() << '\n';

    // bitset::to_ullong

    bitset<4> foo3; // foo: 0000
    foo3.set();     // foo: 1111

    cout << foo3 << " as an integer is: " << foo3.to_ullong() << '\n';

    return 0;
}