#include <iostream>
#include <string>
#include <fstream>
using namespace std;
double num[25];



int main(){
	ifstream in("C:\\temp.txt");
	num[1] = 1;
	for (int i = 2; i <= 25; ++i){
		num[i] = 1;
	for (int j = 1; j < i; ++j)
		num[i] +=1.0/( double(j) / i);
	//	num[i] = 1.0 / num[i];
	}

	for (int i = 1; i <= 22; ++i)
		cout << num[i] << endl;



	return 0;
}