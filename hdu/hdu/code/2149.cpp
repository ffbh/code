#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool ok[1111];


int main(){
	//ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		if (N % (M + 1) == 0)
			cout << "none" << endl;
		else {
			memset(ok, 0, sizeof(ok));
			for (int i = 1; i <= M;++i)
			if ((N - i) % (M + 1)==0||(N-i)<=0)
				ok[i] = 1;
			bool sign = 1;
			for (int i = 1; i <= M;++i)
			if (ok[i]){
				if (sign){
					printf("%d", i);
					sign = 0;
				}
				else
					printf(" %d", i);
			}
			printf("\n");

		}
	}
	return 0;
}