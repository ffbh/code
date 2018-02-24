#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
const double PI = (1 + sqrt(5)) / 2;


int main(){
	ifstream in("C:\\temp.txt");
	int a, b;
	while (in >> a >> b&&a + b){
		int k = b - a;
		if (int(k*PI) != a){
			cout << 1 << endl;
			if (int(k*PI) < a){
				int c = ceil(a - k*PI);
				if (c)
				printf("%d %d\n", a - c, b - c);
			}
			
		}
		else
			cout << 0 << endl;

	}





	return 0;
}