#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N)
		cout << N << endl;

	return 0;
}