#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s;
int N, M;
int data[81];
struct Node{
	bool data[81][81];
}sta, temp;
void Nmul(){
	memcpy(temp.data, sta.data, sizeof(temp.data));
	for (int i = 0; i < N;++i)
	for (int j = 0; j < N; ++j){
		sta.data[i][j] = 0;
		for (int k = 0; k < N; ++k)
			sta.data[i][j] += temp.data[i][k] * temp.data[k][j];
	}
}

void Onemul(){
	int temp[81];
	memcpy(temp, data, sizeof(temp)); 
	for (int i = 0; i < N;++i)
	for (int j = 0; j < 1; ++j){
		data[i] = 0;
		for (int k = 0; k < N; ++k)
			data[i] += sta.data[i][k] * temp[k];
	}
}

void quickmod(){
	for (int i = 0; i < N; ++i)
		data[i] = i;
	while (M){
		if (M % 2)
			Onemul();
		Nmul();
		M /= 2;
	}
}



int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M&&N + M){
		memset(sta.data, 0, sizeof(sta.data));
		for (int i = 0; i < N; ++i){
			int t;
			cin >> t;
			sta.data[i][t - 1] = 1;
		}
		cin.get();
		getline(cin, s);
		quickmod();
		char ans[81];
		for (int i = 0; i < N; ++i)
			ans[data[i]] = s[i];
		for (int i = 0; i < N; ++i)
			putchar(ans[i]);
		cout << endl;
	}
	return 0;
}