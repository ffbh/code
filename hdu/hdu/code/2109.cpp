#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int A[101];
int B[101];


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
			cin >> A[i];
		for (int i = 0; i < N; ++i)
			cin >> B[i];
		sort(A, A + N);
		sort(B, B + N);
		int numA, numB;
		numA = numB = 0;
		for (int i = 0; i < N; ++i){
			if (A[i] == B[i]){
				numA++;
				numB++;
			}
			else if (A[i]>B[i])
				numA += 2;
			else
				numB += 2;
		}
		printf("%d vs %d\n", numA, numB);
	}
	return 0;
}