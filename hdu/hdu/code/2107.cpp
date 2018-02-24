#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		int mmax = INT_MIN;
		while (N--){
			int t;
			cin >> t;
			if (mmax < t)
				mmax = t;
		}
		cout << mmax << endl;
	}





	return 0;
}