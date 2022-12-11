//辗转相除法求公约数（gcd）
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int gcd(int a, int b) {
    int c;
    while ((c = a % b)) {
        a = b;
        b = c;
    }
    return b;
}
//素数判断（isPrime）
#include <math.h>
int isPrime(int x) {
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return 0;
    if (x == 2 || x == 1) return 0;
    return x;
}
//埃式筛选法 素数筛（sieve_Prime）
#include <string.h>
const long long MAX_N = 1e5;
bool prime[MAX_N];
void sieve_Prime(void) {
    memset(prime, true, sizeof(prime));
    for (int i = 2; i < sqrt(MAX_N); i++)
        if (prime[i])
            for (int j = i * i; j <= MAX_N; j += i)
                prime[j] = false;
}
//任意进制转换（modE）
void modE(int x, int y) {
    int a;
    if (x) {
        modE(x / y, y);
        a = x % y;
        if (a < 10) printf("%d", a);
        else printf("%c", a + 55);
    }
}
//快速输入数字（getnum）
int getnum(){
    char c;
    while(!((c = getchar()) >= '0' && c <= '9'));
    int ans = 0;
    while (c >= '0' && c <= '9') {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}
//取最右“1”值位
int lowbit(int x){
    return x & (-x);
    /*
    当一个数与其取负后的值相与
    如果这个数是偶数 则结果是能整除这个偶数的最大的2的幂
    即：m = n & (-n), 则 n % m = 0, 且 m = 2 ^ k
    如果这个数是奇数 则结果必为1
    */
}