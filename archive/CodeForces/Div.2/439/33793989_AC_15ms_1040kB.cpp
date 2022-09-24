#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    LL x, y;
    scanf("%lld %lld", &x, &y);
    if (x == y) printf("1\n");
    else
    {
        if (y-x>=5) printf("0\n");
        else
        {
            LL ans=1;
            for (LL i = x + 1; i <= y; i ++)
            {
                ans = ans * i % 10;
            }
            printf("%lld\n", ans);
        }
    }
}