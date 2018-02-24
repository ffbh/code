#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int num[15001];
int C[32010];
int N;
int lowbit(int x){
	return x&(-x);
}
void Updata(int x){
	for (int i = x; i <32010; i += lowbit(i))
		C[i]++;
}

int getsum(int x){
	int sum = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		sum += C[i];
	return sum;
}

int main(){
	//ifstream in("C:\\temp.txt");
	int M;
	while (cin>>M){
		N = M;
		memset(C, 0, sizeof(C));
		memset(num, 0, sizeof(num));
		int x, y;
		while (M--){
			//in >> x >> y;
			scanf("%d%d", &x, &y);
			x++;
			num[getsum(x)]++;
			Updata(x);
		}
		for (int i = 0; i < N; ++i)
			printf("%d\n", num[i]);
	}
	return 0;
}