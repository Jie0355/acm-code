// Linear Keyboard
#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
	char keyboard[105], words[105];
	int N, sum, i, pos[105];
	scanf("%d", &N);
	getchar();
	while (N --) {
		sum = 0;
		gets(keyboard);
		for (i = 0; i < strlen(keyboard); i++) {
			pos[keyboard[i] - 'a'] = i;
		}
		gets(words);
		for (i = 0; i < strlen(words) - 1; i++) {
			sum += abs(pos[words[i] - 'a'] - pos[words[i + 1] - 'a']);
		}
		printf("%d\n", sum);
	}
	return 0;
}
