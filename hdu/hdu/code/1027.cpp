#include <iostream>
#include <string>
#include <fstream>
#include<algorithm>
using namespace std;
int num[1010];


int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		for (int i = 0; i < N; ++i)
			num[i] = i + 1;
		while (--M)
			next_permutation(num, num + N);
		for (int i = 0; i < N - 1; ++i)
			printf("%d ", num[i]);
		printf("%d\n", num[N - 1]);

	}


	return 0;
}