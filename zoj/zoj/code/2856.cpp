#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[210][210];
int ok[210];
int N;
void change(int n){
	ok[n] = -ok[n];
	for (int i = 1; i <= N; ++i){
		data[i][n] = -data[i][n];
		data[n][i] = -data[n][i];
	}
}

int Test(){
	for (int i = 1; i <= N; ++i){
		int sum = 0;
		for (int j = 1; j <= N; ++j)
			sum += data[i][j] * ok[i];
		sum *= ok[i];
		if (sum < 0)
			return i;
	}
	return -1;

}



int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N){
		for (int i = 1; i <= N; ++i){
			ok[i] = 1;
			for (int j = 1; j <= N; ++j)
				cin >> data[i][j];
		}
		bool flag = 0;
		while (1){
			int ret = Test();
			if (ret == -1)
				break;
			change(ret);
		}
		cout << "Yes" << endl;
		for (int i = 1; i <= N;++i)
		if (ok[i]==1)
			cout << '+' << endl;
		else
			cout << '-' << endl;
	}
	return 0;
}