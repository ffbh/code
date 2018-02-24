#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

long LCM(long a, long b){
	long max = a > b ? a : b;
	long min = a < b ? a : b;
	long t;
	while (max%min){
		t = max%min;
		max = min;
		min = t;
	}
	return a*b/ min;
}

int main(){
	int count;
	long* p;
	scanf("%d", &count);
	int n;
	while (count-- > 0){
		scanf("%d", &n);
		int i = 0;
		long temp;
		p = (long*)malloc(sizeof(long)*n);
		if (!p) exit(0);
		while (i < n){
			scanf("%d", &temp);
			p[i] = temp;
			++i;
		}
		sort(p, p + n);
		temp = p[n - 1];
		for (i = n - 2; i >= 0; --i)
			temp = LCM(temp, p[i]);
		printf("%d\n", temp);
		free(p);
	
	}

	return 0;
}