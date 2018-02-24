#include <iostream>
//#include <fstream>
using namespace std;
int main(){
//	ifstream in("C:\\temp.txt");
	double sum = 0;
	double t;
	while (cin >> t)
		sum += t;
	cout << "$";
	printf("%.2f\n", sum / 12);


	return 0;
}