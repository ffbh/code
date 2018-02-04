#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int a, b;
		cin >> a >> b;
		if (a % (b + 1))
			cout << "Grass" << endl;
		else
			cout << "Rabbit" << endl;
	}





	return 0;
}