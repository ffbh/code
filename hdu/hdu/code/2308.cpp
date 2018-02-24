#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	double sum, mmax;
	while (in >> N&&N){
		sum = mmax = 0;
		while (N--){
			double t;
			in >> t;
			sum += t;
			if (mmax < t)
				mmax = t;
		}
		sum -= mmax;
		if (sum >= mmax)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;


	}


	return 0;
}