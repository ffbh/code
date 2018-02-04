#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int mark[21253];
int gcd(int n, int m){
	if (m == 0)
		return n;
	else
		return gcd(m, n%m);
}

int lcm(int a, int b){
	if (a < b)
		swap(a, b);
	return a*b / gcd(a, b);
}

int slove(int a, int b, int c){
	return lcm(lcm(a, b), c);
}




int main(){
	ifstream in("C:\\temp.txt");
	const int A = 23;
	const int B = 28;
	const int C = 33;
	int a, b, c, d;
	cout << slove(23-4, 28-5, 33-6) << endl;
	/*while (cin >> a >> b >> c >> d&&a + b + c + d != -4){
		a %= A;
		b %= B;
		c %= C;



	}*/





	return 0;
}