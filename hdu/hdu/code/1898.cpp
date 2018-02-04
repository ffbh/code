#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	int A, B, N;
	cin >> N;
	while (N--){
		cin >> A >> B >> T;
		if (T%A == T%B)
			cout << "Both!" << endl;
		else if (T%A < T%B)
			cout << "Sempr!" << endl;
		else
			cout << "Xiangsanzi!" << endl;
	}





	return 0;
}