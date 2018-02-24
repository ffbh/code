#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		cout << (N - 1) / 2 << endl;


	}



	return 0;
}