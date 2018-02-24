#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	string name;
	int v;
	bool operator<(const Node& p)const{
		return v < p.v;
	}
}A[110], B[110], C[110];
int N, M, K;

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M >> K;
		for (int i = 0; i < N; ++i)
			cin >> A[i].name >> A[i].v;
		for (int i = 0; i < M; ++i)
			cin >> B[i].name >> B[i].v;
		for (int i = 0; i < K; ++i)
			cin >> C[i].name >> C[i].v;
		sort(A, A + N);
		sort(B, B + M);
		sort(C, C + K);
		int sum = 0;
		sum += A[N / 2].v;
		sum += B[M / 2].v;
		sum += C[K / 2].v;
		printf("%d %s %s %s\n", sum, A[N / 2].name.c_str(), B[M / 2].name.c_str(), C[K / 2].name.c_str());

	}
	return 0;
}