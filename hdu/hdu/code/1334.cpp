#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	for (int k = 6; k <= 200; ++k){
		int numK = k*k*k;
		for (int a = 2; a*a*a < numK; ++a){
			int numA = a*a*a;
			for (int b = a; numA + b*b*b < numK; ++b){
				int numB = numA + b*b*b;
				for (int c = b; numB + c*c*c <= numK;++c)
				if (numB + c*c*c == numK)
					printf("Cube = %d, Triple = (%d,%d,%d)\n", k, a, b, c);
			}
		}
	}
	return 0;
}