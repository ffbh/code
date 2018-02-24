#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");

	int a, b;
	int T;
	cin >> T;
	while (T--){
		cin >> a >> b;
		if (a % (b + 1))
			cout << "first" << endl;
		else
			cout << "second" << endl;
	}




	return 0;
}