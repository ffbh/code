#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		if (N*N % 2)
			cout << "ailyanlu" << endl;
		else
			cout << "8600" << endl;
	}

	return 0;
}