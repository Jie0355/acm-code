#include <iostream>
#include <algorithm>
using namespace std;
inline int Gcd1(int a, int b)  {  
	while(b ^= a ^= b ^= a %= b);
	return a;
}
inline int Gcd2(int a, int b)  {  
	if (b) while ((a %= b) && (b %= a));
	return a + b;
}
int main() {
	cout << Gcd2(114514, 8795614);
	return 0;
}
