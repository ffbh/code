#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		cout << int(pow(2, N)) - 1 << endl;

	}
	return 0;
}