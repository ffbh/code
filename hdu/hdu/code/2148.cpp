#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[1002];


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int score;
	while (T--){
		int N, M;
		cin >> N >> M;
		int count = 0;
		for (int i = 1; i <= N; ++i)
			cin >> data[i];
		for (int i = 1; i <= N;++i)
		if (data[i] > data[M])
			count++;
		cout << count << endl;
	}

	return 0;
}