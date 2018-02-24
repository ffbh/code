#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	int A, B, C;
	int T;
	cin >> T;
	while (T--){
		cin >> A >> B >> C;
		int i;
		for ( i = 1000; i <= 9999;++i)
		if (i%A == 0 && (i + 1) % B == 0 && (i + 2) % C == 0){
			cout << i << endl;
			break;
		}
		if (i > 9999)
			cout << "Impossible" << endl;



	}

	return 0;
}