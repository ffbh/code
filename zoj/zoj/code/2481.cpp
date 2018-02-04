#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int data[110];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
			cin >> data[i];
		sort(data, data + N);
		N = unique(data, data + N)-data;
		for (int i = 0; i < N - 1; ++i)
			printf("%d ", data[i]);
		printf("%d\n", data[N - 1]);



	}






	return 0;
}