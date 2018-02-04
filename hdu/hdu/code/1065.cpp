#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
#define PI 3.1415926



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	double a, b;
	//cin >> T;
	scanf("%d", &T);
	int CASE = 1;
	while (T--){
		//cin >> a >> b;
		scanf("%lf%lf", &a, &b);
		double r = sqrt(a*a + b*b);
		printf("Property %d: This property will begin eroding in year %d.\n", CASE++, int(PI*r*r / 100 + 0.99999));
	}
	cout << "END OF OUTPUT." << endl;




	return 0;
}