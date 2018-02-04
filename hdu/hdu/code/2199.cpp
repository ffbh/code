#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
double fun(double n)
{
	return 8 * pow(n, 4.0) + 7 * pow(n, 3.0) + 2 * pow(n, 2.0) + 3 * n + 6;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		double Y;
		cin >> Y;
		if (Y<fun(0) || Y>fun(100))
			cout << "No solution!" << endl;
		else{
			double l, r;
			l = 0;
			r = 100;
			while (r - l > 1e-8){
				double m = (r + l) / 2;
				if (fun(m) < Y)
					l = m+1e-8;
				else
					r = m-1e-8;
			}
			printf("%.4f\n", (l+r)/2);

		}


	}





	return 0;
}