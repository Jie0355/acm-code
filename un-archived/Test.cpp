#include <math.h>
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    float sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(-1, i + 1) * (1.0 / (2 * i - 1));
    }
    printf("sum = %f\n", sum);
    return 0;
}
