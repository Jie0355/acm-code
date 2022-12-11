// Odd Grasshopper
#include <stdio.h>
int main() {
	int N;
	long long spot, times;
	scanf("%d", &N);
	while (N--) {
		scanf("%lld %lld", &spot, &times);
		if (spot % 2 == 0) {
			if (times % 2 == 0) {
				if ((times / 2) % 2 == 1) spot++;
			} else {
				if ((times / 2) % 2 == 1)spot += times + 1;
				else spot -= times;
			}
		} else {
			if (times % 2 == 0) {
				if ((times / 2) % 2 == 1)spot--;
			} else {
				if ((times / 2) % 2 == 1)spot -= times + 1;
				else spot += times;
			}
		}
		printf("%lld", spot);
		if (N)printf("\n");
	}
	return 0;
}
