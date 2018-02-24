#include <iostream>
//#include <string>
//#include <fstream>
using namespace std;
int main(){
	//ifstream in("C:\\temp.txt");
	int a, b, k;
	while (cin >> a >> b >> k){
		if (a == 0 && b == 0)break;
		int dig = 1;
		for (int i = 0; i < k; ++i) dig *= 10;
		int c = a%dig;
		int d = b%dig;
		if (c == d)
			cout << -1 << endl;
		else
			cout << a + b << endl;
	
	
	
	}

	return 0;
}