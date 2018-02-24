#include <iostream>
#include <fstream>
using namespace std;
int main(){
	//ifstream in("C:\\temp.txt");
	double H, U, D, F;
	double f;
	double now;
	int day;
	while (cin >> H >> U >> D >> F&&H){
		f = U * F/100;
		now = 0;
		day = 0;
		while (now >= 0 ){
			day++;
			now += U;
			if (now > H)break;
			now -= D;
			U -= f;
		}
		if (now < 0)
			printf("failure on day %d\n", day);
		else
			printf("success on day %d\n", day);
	
	}

	return 0;
}