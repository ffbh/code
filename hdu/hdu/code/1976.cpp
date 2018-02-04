#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	int a1, b1, c1, a2, b2, c2;
	cin >> T;
	while (T--){
		cin >> a1 >> b1 >> c1;
		cin >> a2 >> b2 >> c2;
		if (a1 != a2){
			if (a1 > a2)
				cout << "First" << endl;
			else
				cout << "Second" << endl;
		}
		else if (b1 != b2){
			if (b1 > b2)
				cout << "First" << endl;
			else
				cout << "Second" << endl;
		}
		else{
			if (c1 == c2)
				cout << "Same" << endl;
			else if (c1 > c2)
				cout << "First" << endl;
			else
				cout << "Second" << endl;
		}
	}
	return 0;
}