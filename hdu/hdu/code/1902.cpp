#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int A[20001];
int B[20001];


int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M&&N+M){
		for (int i = 0; i < N; ++i)
			//cin >> A[i];
			scanf("%d", &A[i]);
		for (int i = 0; i < M; ++i)
			//cin >> B[i];
			scanf("%d", &B[i]);
		if (M < N)
			cout << "Loowater is doomed!" << endl;
		else{
			sort(A, A + N);
			sort(B, B + M);
			int sum = 0;
			int num = 0;
			int L,R = 0;
			for (L = 0; L < N; ++L){
				while (R < M){
					if (A[L] <= B[R]){
						sum += B[R];
						R++;
						num++;
						break;
					}
					R++;
				}
			}
			if (num == N)
				cout << sum << endl;
			else
				cout << "Loowater is doomed!" << endl;
		}

	}

	return 0;
}