#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    // constructing bitsets

    bitset<16> foo;
    bitset<16> bar(0xfa2);
    bitset<16> baz(string("0101111001"));

    cout << "foo: " << foo << '\n';
    cout << "bar: " << bar << '\n';
    cout << "baz: " << baz << '\n';

    return 0;
}