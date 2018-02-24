#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int gcd(int a, int b){
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	return gcd(b, a%b);
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int a, b;
		cin >> a >> b;
		if (gcd(a, b) == 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

	}

	return 0;
}