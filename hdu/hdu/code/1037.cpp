#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if (a >= 168 && b >= 168 && c >= 168){
		cout << "NO CRASH" << endl;
		return 0;
	}
	if (a < 168)
		cout << "CRASH " << a << endl;
	else if (b < 168)
		cout << "CRASH " << b << endl;
	else
		cout << "CRASH " << c << endl;

	return 0;
}