#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		printf("%d ", CASE++);
		double data;
		string s;
		cin >> data >> s;
		if (s == "kg")
			printf("%.4f lb\n", 2.2046*data);
		else if (s == "l")
			printf("%.4f g\n", 0.2642*data);
		else if (s == "g")
			printf("%.4f l\n", 3.7854*data);
		else
			printf("%.4f kg\n", 0.4536*data);
	}





	return 0;
}