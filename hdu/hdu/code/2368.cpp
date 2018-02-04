#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	double a, b, c;
	int CASE = 1;
	while (cin >> a&&a){
		cin >> b >> c;
		b = sqrt((b*b+c*c) / 4.0);
		if (b > a)
			printf("Pizza %d does not fit on the table.\n", CASE++);
		else
			printf("Pizza %d fits on the table.\n", CASE++);
	}
	return 0;
}