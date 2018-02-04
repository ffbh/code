#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int  CASE = 1;
	while (cin >> N&&N>0){
		printf("Sum of #%d is ", CASE++);
		int sum = 0;
		int temp;
		while (N--){
			cin >> temp;
			sum += temp;
		}
		cout << sum << endl;

	}
	return 0;
}