#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[101];


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		int sum = 0;
		for (int i = 0; i < N; ++i){
			cin >> data[i];
			sum ^= data[i];
		}
		if (!sum)
			cout << 0 << endl;
		else{
			int num = 0;
			for (int i = 0; i < N;++i)
			if ((sum^data[i]) < data[i])
				num++;
			cout << num << endl;
		}
	}

	return 0;
}