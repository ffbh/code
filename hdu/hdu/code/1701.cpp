#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	double x, y;
	int T;
	cin >> T;
	while (T--){
		cin >> x >> y;
		for (int i = 1;; ++i){
			double k1 = i*x/100;
			double k2 = i*y/100;
			int up = ceil(k1);
			if (up <= k2&&up!=k1){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}