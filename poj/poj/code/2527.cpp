#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int N, K, coe[10010];

int main(){
	//ifstream in("C:\\input.txt");
	while (cin >> N >> K&&N >= 0){
		for (int i = 0; i <= N; ++i)
			cin >> coe[N-i];
		if (K == 0){
			cout << 0 << endl;
			continue;
		}

		for (int i = 0; i + K <= N; ++i){
			coe[i+K] -= coe[i];
		}
		int pos = N - K + 1;
		if (pos <= 0)pos = 0;
		while (N>=pos){
			printf("%d ", coe[N--]);
		}
		cout << endl;
	}
















	return 0;
}