#include <iostream>
using namespace std;

void fun(int* p, int len){
	for (int i = 1; i <= len;++i)
	if (p[i] % 2) p[i]++;
}

bool stop(int* p, int len){
	int num = p[1];
	for (int i = 2; i <= len;++i)
	if (p[i] != num) return false;
	return true;
		

}
int main(){
	int n;
	int max, min,time;
	int m, k;
	while (cin >> n&&n){
		int* p1 = (int*)malloc((n + 1)*sizeof(int));
		int* p2 = (int*)malloc((n + 1)*sizeof(int));
		if (!p1 || !p2) exit(0);
		int ii = 1;
		max = 0;
		min = 9999999;
		while (ii <= n){
			scanf("%d", &p1[ii]);
			if (max < p1[ii]){
				max = p1[ii];
				m = ii;
			}
			if (min > p1[ii]){
				min = p1[ii];
				k = ii;
			}
			++ii;
		}
		time = 0;
		while (1){
			p2[n] = p1[1] / 2;
			for (int i = 1; i < n; ++i)
				p2[i] = p1[i+1] / 2;
			for (int i = 1; i <= n; ++i)
				p1[i] /= 2;
			for (int i = 1; i <= n; ++i)
				p1[i] += p2[i];
			fun(p1, n);
			time++;
			if (p1[k] == p1[m] && stop(p1, n))
				break;
		}
		cout << time << " " <<p1[1] <<endl; 
		delete[] p1;
		delete[] p2;

	}

	return 0;
}