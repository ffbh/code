#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool ok[2002][2002];


int main(){
	ifstream in("C:\\temp.txt");
	ok[1][1] = 1;
	for (int i = 1; i <= 2000; ++i)
		ok[i][1] = ok[1][i] = i % 2?0:1;
	for (int i = 2; i <= 2000;++i)
	for (int j = 2; j <= 2000;++j)
	if (!ok[i - 1][j] || !ok[i][j - 1] || !ok[i - 1][j - 1])
		ok[i][j] = 1;
	else
		ok[i][j] = 0;
	int m, n;
	while (cin >> m >> n&&m+n){
		if (ok[m][n])
			cout << "Wonderful!" << endl;
		else
			cout << "What a pity!" << endl;
	}
	return 0;
}