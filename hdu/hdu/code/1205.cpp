#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
//	ifstream in("C:\\temp.txt");
	int MMAX;
	_int64 SUM;
	int T;
	cin >> T;
	while (T--){
		SUM = 0;
		MMAX = -1;
		int M;
		cin >> M;
		while (M--){
			int  t;
		//	in >> t;
			scanf("%d", &t);
			SUM += t;
			if (t > MMAX)
				MMAX=t;
		}
		SUM -= MMAX;
		if (MMAX > SUM + 1)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}