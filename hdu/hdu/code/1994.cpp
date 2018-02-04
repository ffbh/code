#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	double A, B, C, D, E;
	cin >> T;
	while (T--){
		cin >> A >> B >> C >> D >> E;
		double temp;
		temp = A*(1.0 + C/ 100*B / 365);
		printf("%.1f\n", temp *(1.0 + E / 100));
		printf("%.1f\n", A*(1 + D / 100 * (B + 365) / 365));
	}





	return 0;
}