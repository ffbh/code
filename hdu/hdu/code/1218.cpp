#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string map[12];


int main(){
//	ifstream in("C:\\temp.txt");
	string s;
	int N, M;
	while (cin >> s&&s == "START"){
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
			cin >> map[i];
		cin >> s;
		for (int i = 0; i < N - 1; ++i){
			for (int j = 0; j < M - 1; ++j)
				putchar(int((map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1])) / 4);
			putchar('\n');
		}
	}
	return 0;
}