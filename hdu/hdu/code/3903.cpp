#include <stdio.h>
#include <math.h>


int main(void){
	int t,u;
	__int64 C,s;
	int a, b, c,n,m,k;
	scanf("%d", &t);
	for (u = 0; u < t; u++){
		scanf("%d%d%d%d%d%d",&a,&b,&c,&n,&m,&k);
		C = (__int64)4 * a*b*a*b -((__int64)a*a + b*b - c*c)*((__int64)a*a + b*b - c*c);
		s = (__int64)sqrt(C);
		if (s*s == C){
			printf("YES\n");
		}
		else{

			printf("NO\n");
		}

	}
	

	return 0;
}

