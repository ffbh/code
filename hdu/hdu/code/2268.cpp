#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int a, b, c;
	while (cin >> a >> b >> c){
		//if (a >= b)
		//	printf("%.3f\n", double(a) / c);
		//else{
		
			printf("%.3f\n", (3.0*c)/(b+2*a));
		//}
	}
	return 0;
}