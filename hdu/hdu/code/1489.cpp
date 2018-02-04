#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	_int64 sum, temp;
	while (cin >> N&&N){
		sum = temp = 0;
		while (N--){
			int t;
			cin >> t;
			temp += t;
			sum += abs(temp);
		}
		cout << sum << endl;
	}
	return 0;
}