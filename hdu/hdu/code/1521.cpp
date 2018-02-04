#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
double data[15];
double C1[20], C2[20];
int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	data[0] = 1;
	for (int i = 1; i < 15; ++i)
		data[i] = data[i - 1] * i;
	while (cin >> N >> M){
		memset(C1, 0, sizeof(C1));
		memset(C2, 0, sizeof(C2));
		C1[0] = 1.0;
		while (N--){
			int t;
			cin >> t;
			for (int i = 0; i <= M; ++i)
			for (int j = 0; j <= t&&j + i <= M; ++j)
				C2[i + j] += C1[i] / data[j];
			memcpy(C1, C2, sizeof(C1));
			memset(C2, 0, sizeof(C2));
		}
		printf("%d\n", (int)round(C1[M] * data[M]));
	}
	return 0;
}