#include <iostream>
#include <fstream>
using namespace std;
int data[1010][1010];
int temp[1010][1010];
int temp2[1010][1010];
int A, B;
int N, M;
void DP(){
	int sum;
	for (int i = 0; i < N; ++i){
		sum = 0;
		int j;
		for (j = 0; j < B; ++j)
			sum += data[i][j];
		j=0;
		temp[i][j] = sum;
		for (j++; j <= M-B; ++j){
			sum += data[i][j+B-1];
			sum -= data[i][j-1];
			temp[i][j] = sum;
		}
	}
	for (int j = 0; j <= M-B; ++j){
		sum = 0;
		int i;
		for ( i = 0; i<A; ++i)
			sum += temp[i][j];
		i = 0;
		temp2[i][j] = sum;
		for (i++; i+A<=N; ++i){
			sum += temp[i+A-1][j];
			sum -= temp[i-1][j];
			temp2[i][j] = sum;
		}
	}
}





int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	
	cin >> T;
	while (T--){
		int mmax = INT_MIN;
		cin >> N >> M >> A >> B;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j)
			//	in >> data[i][j];
			scanf("%d", &data[i][j]);
		DP();
		for (int i = 0; i <= N-A;++i)
		for (int j = 0; j <= N-B; ++j)
		if (mmax < temp2[i][j])
			mmax = temp2[i][j];
		cout << mmax << endl;
		
	}

	return 0;
}