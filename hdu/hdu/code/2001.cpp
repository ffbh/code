#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	double x1, x2, y1, y2;
	while (cin >> x1 >> y1 >> x2 >> y2){
		double ans = sqrt(pow(x1 - x2, 2)+ pow(y1 - y2, 2));
		printf("%.2f\n", ans);
	}
	return 0;
}