#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int x, y;
	bool zero;
	while (cin >> x >> y >> zero&&x + y + zero){
		x -= 7;
		y -= 7;
		if (x % 2 == 0 || y % 2 == 0)
			cout << x * y / 2 << endl;
		else{
			if (zero)
				cout << x * y / 2+1 << endl;
			else
				cout << x * y / 2<< endl;
		}
	}
	return 0;
}