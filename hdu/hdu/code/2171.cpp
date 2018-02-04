#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string name[21];


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	string s;
	int N;
	while (T--){
		cin >> name[0];
		int size = 1;
		while (cin.get() != '\n'){
			cin >> name[size++];
		}
		cin >> s;
		cin >> N;
		for (int i = 0; i < size;++i)
		if (name[i] == s){
			N += i-1;
			break;
		}
		N += size;
		N %= size;
		cout << name[N] << endl;
	}





	return 0;
}