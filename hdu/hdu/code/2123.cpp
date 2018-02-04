#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j < N; ++j)
				printf("%d ", i*j);
			printf("%d\n", i*N);
		}
	}





	return 0;
}