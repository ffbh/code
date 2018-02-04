#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int a, b, c;
	int T;
	cin >> T;
	while (T--){
		cin >> a >> b >> c;
		if (a){
			double ans = b*b - 4 * a*c;
			if (ans > 0)
				cout << 2 << endl;
			else if (ans == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (b)
			cout << 1 << endl;
		else{
			if (c)
				cout << 0 << endl;
			else
				cout << "INF" << endl;
		}
	}
	return 0;
}