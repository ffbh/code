#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
#define MMAX (1100)
double data[MMAX];
void Init(){
	data[0] = 1.0;
	for (int i = 1; i < MMAX; ++i)
		data[i] = data[i - 1]*i;
}
double C1[MMAX], C2[MMAX];

int main(){
//	ifstream in("C:\\temp.txt");
	Init();
	int N, M;
	while (cin >> N >> M){
		memset(C1, 0, sizeof(C1));
		memset(C2, 0, sizeof(C2));
		C1[0] = 1.0;
		while (N--){
			int temp[MMAX];
			int k;
			cin >> k;
			for (int i = 0; i < k; ++i)
				cin >> temp[i];
			sort(temp, temp + k);
			k = unique(temp, temp + k) - temp;
			for (int i = 0; i <= M;++i)
			for (int j = 0; j < k&&i + temp[j] <= M; ++j)
				C2[i + temp[j]] += C1[i] / data[temp[j]];
			memcpy(C1, C2, sizeof(C1));
			memset(C2, 0, sizeof(C2));
		}
		printf("%.0f\n", C1[M] * data[M]);
	}
	return 0;
}