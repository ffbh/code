#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int num[21];
	num[0] = 1;
	num[1] = 1;
	for (int i = 2; i <= 20; ++i)
		num[i] = num[i - 1] + num[i - 2];
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		cout << num[N] << endl;
	}




	return 0;
}