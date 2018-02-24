#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
//	ifstream in("C:\\temp.txt");
	int a, b;
	while (cin >> a >> b){
		if ((a + b) % 86 == 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}





	return 0;
}