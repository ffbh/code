#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
int T, N;

int pace[100];


bool DFS(int a, int b, int pos,int sum){


	if (a > N || b > N || sum > 60)
		return 0;

	if (a == N || b == N){
		for (int i = 0; i < pos;++i)
		for (int j = 0; j < pace[i]; ++j)
			printf("%d", i % 2);
		return 1;
	}

	if ((N - a) % b == 0 && (N - a) / b + sum <= 60){
		for (int i = 0; i < pos; ++i)
		for (int j = 0; j < pace[i]; ++j)
			printf("%d", i % 2);
		int k = (N - a) / b;
		while (k-->0){
			putchar('0');
		}
		return 1;

	}

	if ((N - b) % a == 0 && (N - b) / a + sum <= 60){
		for (int i = 0; i < pos; ++i)
		for (int j = 0; j < pace[i]; ++j)
			printf("%d", i % 2);
		int k = (N - b) / a;
		while (k-->0){
			putchar('1');
		}
		return 1;

	}

	int r = 60 - sum;



	if (pos % 2 == 0){
		for (int i = 1; i <= r; ++i){
			pace[pos] = i;
			if (DFS(a + b*i, b, pos + 1, sum + i)){
				return 1;
			}
			if (a + b*i > N)
				break;
		}
	}
	else{
		for (int i = 1; i <= r; ++i){
			pace[pos] = i;
			if (DFS(a , b + a* i, pos + 1, sum + i)){
				return 1;
			}
			if (b + a*i > N)
				break;
		}

	}




	return 0;
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> T;
	while (T--){
		cin >> N;
	//	scanf("%d", &N);
		putchar('0');
		DFS(1, 1, 0, 1);
		cout << endl;
	}
	
	return 0;
}