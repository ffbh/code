#include <iostream>
#include <string>
#include <fstream>
using namespace std;
_int64 data[60];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		for (int i = 0; i < N; ++i)
			cin >> data[i];
		_int64 sum = 0;
		for (int i = N - 1; i >= 0; --i){
			sum += data[i];
			for (int j = 0; j < i; ++j)
				data[j] += data[i];
		}
		cout << sum << endl;

	}




	return 0;
}