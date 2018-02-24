#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
string s[10] = { "", "1011011", "0000110", "0010010",
"0011001", "0110000", "0100000", "1011010", "0000000", "0010000" };
int key[10][7];


void Init(){
	for (int i = 1; i <= 9;++i)
	for (int j = 0; j < 7; ++j)
		key[i][j] = s[i][j] - '0';
}
int T, N;
int X[10];
char str[10][10];

int A[10],B[10];

int main(){
	ifstream in("C:\\input.txt");
	Init();
	//in >> T;
	scanf("%d", &T);
	while (T-->0){
	//	in >> N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i){
			//	in >> X[i] >> str[i];
			scanf("%d", &X[i]);
			scanf("%s", str[i]);
		}
		for (int i = 0; i < 7; ++i){
			A[i] = B[i] = 0;
			for (int j = 0; j < N; ++j){
				A[i] = A[i] * 2 + key[X[j]][i];
				B[i] = B[i] * 2 + str[j][i]-'0';
			}
		}

		sort(A, A + 7);
		sort(B, B + 7);
		bool ok = 1;
		for (int i = 0; i < 7; ++i){
			if (A[i] != B[i]){
				ok = 0;
				break;
			}
		}

		if (ok)
			printf("YES\n");
		else
			printf("NO\n");

	}















	return 0;
}