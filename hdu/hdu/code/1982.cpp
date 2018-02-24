#include <stdio.h>
int main(){
	int T;
	T = 0;
	char c;
	while ((c = getchar()) != '\n')
		T = T * 10 + c - '0';
	while (T--){
		int N;
		while (1){
			N = 0;
			c = getchar();
			while (c >= '0'&&c <= '9'){
				N = N * 10 + c - '0';
				c = getchar();
			}
			if (N)
				putchar(N + 'A'-1);
			if (c == '#')
				putchar(' ');
			if (c == '\n')
				break;
		}
		putchar('\n');
	}
	return 0;
}