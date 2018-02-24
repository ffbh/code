#include <iostream>
#include <fstream>
using namespace std;
int N;
int C[100010];

int lowbit(int x){
	return x&(-x);
}


void update(int x, int v){
	for (int i = x; i <= N; i += lowbit(i))
		C[i] += v;

}

int getSum(int x){
	int ans = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		ans += C[i];
	return ans;
}



int main(){
	ifstream in("C:\\temp.txt");
	int a, b;
	while (cin >> N&&N){
		memset(C, 0, sizeof(C));
		int K = N;
		while (K--){
			scanf("%d%d", &a, &b);
			update(a, 1);
			update(b + 1, -1);
		}
		for (int i = 1; i < N; ++i)
			printf("%d ", getSum(i));
		printf("%d\n", getSum(N));
	}
	return 0;
}