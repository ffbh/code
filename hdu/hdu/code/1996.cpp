#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	_int64 T, N;
	cin >> T;
	while (T--){
		cin >> N;
		cout << _int64(pow(3, N)) << endl;


	}





	return 0;
}