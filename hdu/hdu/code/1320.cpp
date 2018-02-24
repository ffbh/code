#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int data[51];
int C[52];
int N;
int lowbit(int x){
	return x&(-x);
}

int getsum(int x){
	int sum = 0;
	for (int i = x; i <= N; i += lowbit(i))
		sum += C[i];
	return sum;
}

void update(int x){
	for (int i = x; i > 0; i -= lowbit(i))
		C[i]++;
}

int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N&&N){
		char c;
		cin >> c;
		if (c == 'P'){
			int M = N;
			memset(C, 0, sizeof(C));
			while (M--){
				int t;
				cin >> t;
				//scanf("%d", &t);
				data[t] = getsum(t);
				update(t);
			}
			for (int i = 1; i < N; ++i)
				printf("%d ", data[i]);
			printf("%d\n", data[N]);
		}
		else{
			memset(data, 0, sizeof(data));
			for (int i = 1; i <= N; ++i){
				int k = -1;
				int t;
				cin >> t;
				for(int j=1;j<=N;++j){
					if (!data[j]) k++;
					if (k == t){
						data[j] = i;
						break;
					}
				}
			}
			for (int i = 1; i < N; ++i)
				printf("%d ", data[i]);
			printf("%d\n", data[N]);

		}
	}
	return 0;
}