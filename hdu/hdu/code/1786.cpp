#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N, K;
	while (cin >> N >> K&&N + K){
		int max = INT_MIN;
		while (N--){
			int t;
			cin >> t;
			if (max < t)
				max = t;
		}
		cout << int(double(K) / max + 0.99999)*3 << endl;
	}
	return 0;
}