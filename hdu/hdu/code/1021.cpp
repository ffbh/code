#include <cstdio>

using namespace std;

int main(){
	int n,m;
	while (scanf("%d", &n) != EOF){
		m = n % 8;
		if (m == 2 || m == 6) printf("yes\n");
		else printf("no\n");
	
	}



	return 0;
}