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
int N;
bool data[60][60];
long long arr[120][60];
void encode(int p){
	for (int i = 0; i < N; ++i){
		arr[p][i] = 0;
		for (int j = 0; j < N; ++j){
			arr[p][i] = arr[p][i] * 2 + data[i][j];
		}
	}
}

bool judge(int p){
	for (int k = 1; k < p; ++k){
		bool ok = 1;
		for (int i = 0; i < N; ++i){
			if (arr[k][i] != arr[p][i]){
				ok = 0;
				break;
			}
		}
		if (ok)
			return 0;//dup

	}
	return 1;///no dup
}


bool tmp[60][60];
void rarote(){
	for (int i = 0; i < N;++i)
	for (int j = 0; j < N; ++j){
		tmp[i][j] = data[j][N - i - 1];
	}
	for (int i = 0; i < N;++i)
	for (int j = 0; j < N; ++j){
		data[i][j] = tmp[i][j];
	}

}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	while (in >> N&&N){
		for (int i = 0; i < 60;++i)
		for (int j = 0; j < 60; ++j)
			data[i][j] = 0;

		bool e = 0;
		for (int i = 1; i <= 2 * N; ++i){
			int x, y;
			char op;
			in >> x >> y >> op;
			if (!e){
				x--;
				y--;
				if (op == '+'){
					data[x][y] = 1;
				}
				else{
					data[x][y] = 0;
				}
				for (int k = 0; k < 4; ++k){
					rarote();
					encode(i);
					if (!judge(i)){
						e = 1;
						printf("Player %d wins on move %d\n", 1 + i % 2, i);
						break;
					}
				}
			}


		}
		if (!e){
			cout << "Draw" << endl;
		}

	}


	return 0;
}