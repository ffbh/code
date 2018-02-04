#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[15];

int main(){
	ifstream in("C:\\temp.txt");
	int T, count, d;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		memset(data, 0, sizeof(data));
		count = 0;
		d = 2;
		int num = N;
		for (int i = 1; num; ++i){
			if (i == N+1)i = 1;
			if (!data[i]){
				count++;
				if (count == d){
					count = 0;
					data[i] = d - 1;
					d++;
					num--;
				}
			}

		}
		for (int i = 1; i < N; ++i)
			printf("%d ", data[i]);
		printf("%d\n", data[N]);
	}
	return 0;
}