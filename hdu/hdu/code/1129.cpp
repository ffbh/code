#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int GetV(char c){
	if (c == '_')
		return 0;
	else if (c == '.')
		return 27;
	else
		return c - 'a' + 1;
}

char GetA(int n){
	if (n == 0)
		return '_';
	else if (n == 27)
		return '.';
	else
		return n + 'a' - 1;
}
int main(){
	ifstream in("C:\\temp.txt");
	int K;
	string C;
	while (cin >> K >> C&&K){
		int N = C.length();
		string temp = C;
		for (int i = 0; i < N; ++i){
			temp[K*i%N] = GetA((GetV(C[i]) + i) % 28);
		}
		cout << temp << endl;
	}
	return 0;
}