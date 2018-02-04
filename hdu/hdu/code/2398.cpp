#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	double a, b, c;
	while (cin >> a >> b >> c){
		b /= 100.0;
		int ans = 0;
		while (a < c){
			a += a*b;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}