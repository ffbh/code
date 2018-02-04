#include <iostream>
//#include <fstream>
using namespace std;

int main(){
	//ifstream in("C:\\temp.txt");
	int a, b;
	while (cin >> a >> b){
		a %= 10;
		if (b == 0){
			cout << 1 << endl;
			continue;
		}
		if (a == 0 || a == 1 || a == 5 || a == 6)
			cout << a << endl;
		else if (a == 4 || a == 9){
			b %= 2;
			if (b == 1)
				cout << a << endl;
			else
				cout << (a*a) % 10 << endl;
		}
		else {
			b %= 4;
			if (b == 1)
				cout << a << endl;
			else if (b == 2)
				cout << (a*a) % 10 << endl;
			else if (b == 3)
				cout << (a*a*a) % 10 << endl;
			else
				cout << (a*a*a*a) % 10 << endl;
		}
	
	
	}

	return 0;
}