#include<iostream>
using namespace std;
const double PI = 3.1415927;
int  main(){
	double d,t;
	int s ;
	int c=1;
	while (cin >> d >> s >> t){
		if (s == 0) break;
		double d1 = d / 5280 / 12 * PI*s;
		double d2 = d1 / t * 60 * 60;
		printf("Trip #%d: %.2f %.2f\n", c++,d1,d2);
	}


	return 0;
}

