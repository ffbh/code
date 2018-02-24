#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#define MMAX (180010)
vector<int> prime;
bool ok[MMAX];


void Init(){
	prime.push_back(-1);
	for (int i = 2; i < MMAX;++i)
	if (!ok[i]){
		prime.push_back(i);
		for (int j = 1; i*j < MMAX; ++j)
			ok[i*j] = 1;
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	Init();
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		cout << prime[N] << endl;

	}





	return 0;
}