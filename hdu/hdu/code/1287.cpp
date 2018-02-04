#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
int num[100100];
bool fun(char C,char c){
	char d = c^C;
	if (d >= 'A'&&d <= 'Z')
		return 1;
	return 0;
}
int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	char m;
	while (cin >> N){
		for (int i = 0; i < N; ++i)
			scanf("%d", &num[i]);
			//in >> num[i];
		for (char c = 'A'; c <= 'Z'; ++c){
			int i;
			for (i = 0; i < N;++i)
			if (!fun(c, num[i]))break;

			if (i == N){
				m = c;
				break;
			}
		}
		for (int i = 0; i < N; ++i)
			printf("%c", num[i] ^ m);
		cout << endl;
	
	}

	return 0;
}