#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	double R, V1, V2;
	const double PI = acos(-1.0); 
	while (cin >> R >> V1 >> V2){
		if (V1 >= V2)
			cout << "Yes" << endl;
		else{
			double r = V1*R / V2;
			double t1 = PI*R / V2;
			double t2 = (R - r) / V1;
			if (t1 > t2)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}


	}



	return 0;
}