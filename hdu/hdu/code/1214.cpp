#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		int M = N / 2;
		N -= M;
		cout << N*(N - 1) / 2 + M*(M - 1) / 2 << endl;
	}
	return 0;
}