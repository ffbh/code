#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	int N;
	cin >> T;
	while (T--){
		cin >> N;
		int sum = 0;
		while (N--){
			int t;
			cin >> t;
			sum ^= (t-1);
		}
		if (sum)
			cout << "John" << endl;
		else
			cout << "Brother" << endl;
	}
	return 0;
}