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
		int sum = 0;
		int a, b;
		cin >> N;
		while (N--){
			cin >> a >> b;
			sum ^= (a % (b + 1));
		}
		if (!sum)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;


	}





	return 0;
}