#include <iostream>
#include <string>
#include <fstream>

using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	unsigned _int64  N;
	cin >> T;
	while (T--){
		cin >> N;
		cout << N*N*N << " " << (N+1)*(N+1)*(N+1) << endl;
	}
	return 0;
}