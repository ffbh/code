#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	double N;
	while (in >> N){
		int K = double(log(N)) / log(18);
		if (K <= 9)
			cout << "Stan wins." << endl;
		else
			cout << "Ollie wins." << endl;
	}



	return 0;
}