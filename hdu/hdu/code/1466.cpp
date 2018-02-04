#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
bool ok[30][300];

void Init(){
	memset(ok, 0, sizeof(ok));
	ok[1][0] = ok[0][0] = 1;
	for (int i = 1; i < 22;++i)
	for (int j = 0; j <= i; ++j){
		if (i == 4 && j == 2){
			int t = 0;
		}
		for (int k = 0; k < 300; ++k)
		if (ok[j][k]){
			ok[i][(i - j)*j + k] = 1;
		}
	}




}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	int N;
	while (cin >> N){
		cout << 0;
		for (int i = 1; i < 300;++i)
		if (ok[N][i])
			cout << " " << i;
		cout << endl;

	}
















	return 0;
}