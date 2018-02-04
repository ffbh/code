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
		_int64 a, b;
		cin >> a >> b;
		cout << _int64(pow(2,a - b)) << endl;

	}
	return 0;
}