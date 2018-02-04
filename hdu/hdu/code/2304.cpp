#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		int sum = 1 - N;
		while (N--){
			int t;
			cin >> t;
			sum += t;
		}
		cout << sum << endl;
	}
	return 0;
}