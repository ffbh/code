#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
char num[110][30];
int N,M;
int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	
	while (cin >> M&&M){
		cin >> s;
		N = s.length() / M;
		memset(num, 0, sizeof(num));
		int p = 0;
		for (int i = 0; i < N; ++i){
			if (i % 2 == 1)
			for (int j = M - 1; j >= 0; --j)
				num[i][j] = s[p++];
			else
				for (int j = 0; j < M; ++j)
					num[i][j] = s[p++];
		
		}//for
		for (int j = 0; j < M;++j)
		for (int i = 0; i < N; ++i)
			printf("%c", num[i][j]);
		cout << endl;
	
	}

	return 0;
}