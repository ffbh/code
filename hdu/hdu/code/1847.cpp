#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool ans[1001];


int main(){
	ifstream in("C:\\temp.txt");
	for (int i = 1; i <= 1000; i *= 2)
		ans[i] = 1;
	for (int i = 1; i <= 1000;++i)
	if (ans[i] == 0)
		for (int j = 1; i - j > 0;j*=2)
		if (ans[i - j] == 0){
			ans[i] = 1;
			break;
		}
		int N;
		while (cin>>N)
		if (ans[N])
			cout << "Kiki" << endl;
		else
			cout << "Cici" << endl;


	




	return 0;
}