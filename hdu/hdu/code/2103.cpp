#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
int data[50];
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int M, N;
		cin >> M >> N;
		int k = M;
		for (int i = 1; i <= N; ++i)
			cin >> data[i];
		for (int i = 1; i <=min(N, M);++i)
		if (data[i]){
			k = i;
			break;
		}
		int ans = N - k;
		if (ans>0){
			printf("%d0000 RMB\n", int(pow(2,ans)) - 1);
		}
		else
			cout << "0 RMB" << endl;
	}
	return 0;
}