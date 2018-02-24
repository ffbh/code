#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string map[11];
void fun(int N){
	string temp[11];
	for (int i = 0; i < N; ++i)
		temp[i] = map[i];
	for (int i = 0; i < N;++i)
	for (int j = 0; j < N; ++j)
		map[i][j] = temp[j][N - i-1];
}

int main(){
	//ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		M = ((M % 4) + 4) % 4;
		if (M == 1)
			M = 3;
		else if (M == 3)
			M = 1;
		for (int i = 0; i < N; ++i)
			cin >> map[i];
		while (M--)
			fun(N);
		for (int i = 0; i < N; ++i)
			cout << map[i] << endl;


	}





	return 0;
}