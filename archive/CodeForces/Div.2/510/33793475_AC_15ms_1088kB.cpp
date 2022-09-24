#include <bits/stdc++.h>
using namespace std;
int main()
{
    int classes, num, a[10001];
    scanf("%d %d", &classes, &num);
    for (int i = 0; i < classes; i ++) scanf("%d", &a[i]);
    sort(a, a + classes);
    int max = a[classes - 1] + num;
    int i = 0, flag = 0;
    while (classes != 1)
    {
        if (a[i] < a[i + 1])
        {
            if (num >= a[i + 1] - a[i])
            {
                num = num - a[i + 1] + a[i];
                a[i] = a[i + 1];
                flag = 1;
            }
            else
            {
                a[i] += num;
                num = 0;
                break;
            }
        }
        else i ++;
        if (i == classes - 1)
        {
            int p;
            if (num % classes == 0) p = num / classes - 1;
            else p = num / classes;
            a[classes - 1] += p + 1;
        }
        if (flag == 1)
        {
            i = 0;
            flag = 0;
        }
    }
    int min;
    if (classes == 1)  min = a[classes - 1] + num;
    else min = a[classes - 1];
    printf("%d %d", min, max);
    return 0;
}