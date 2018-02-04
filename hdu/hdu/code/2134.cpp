#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	const double PI = acos(-1.0);
	int N;
	while (cin >> N&&N){
		double all = PI*N*N;
		double first = all / 3;
		first = sqrt(first / PI);
		double second = all / 3 * 2;
		second = sqrt(second / PI);
		printf("%.3f %.3f\n", first, second);



	}




	return 0;
}