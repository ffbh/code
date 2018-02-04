#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int a, b, c;
		cin >> a >> b >> c;
		if (a < b - c)
			cout << "advertise" << endl;
		else if (a == b - c)
			cout << "does not matter" << endl;
		else
			cout << "do not advertise" << endl;


	}








	return 0;
}