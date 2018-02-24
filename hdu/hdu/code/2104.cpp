#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int gcd(int a, int b){
	if (b == 0)
		return a;
	else
		return gcd(b,a%b);
}


int main(){
	ifstream in("C:\\temp.txt");
	int a, b;
	while (cin >> a >> b){
		if (a == -1 & b == -1)
			break;
		if (a < b)
			swap(a, b);
		if (gcd(a, b) == 1)
			cout << "YES" << endl;
		else
			cout << "POOR Haha" << endl;
	}





	return 0;
}