#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[10001];


int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M&&N + M){
		memset(data, 0, sizeof(data));
		N *= M;
		while (N--){
			int t;
			//cin >> t;
			scanf("%d", &t);
			data[t]++;
		}
		int max, sec;
		max = sec = 0;
		for (int i = 1; i <= 10000;++i)
		if (data[i] > max){
			sec = max;
			max = data[i];
		}
		else if (data[i] > sec){
			sec = data[i];
		}
		bool sign = 0;
		for (int i = 1; i <= 10000;++i)
		if (data[i] == sec){
			if (!sign){
				sign = 1;
				printf("%d", i);
			}
			else
				printf(" %d", i);
		}
		putchar('\n');
	}
	return 0;
}