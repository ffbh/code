#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[30];
bool vis[30];

int main(){
	ifstream in("C:\\input.txt");
	int N;
	while (cin >> N&&N){
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i)
			cin >> data[i];
		for (int i = 1; i < N;++i)
		if (data[i] == data[i - 1])
			vis[i] = 1;
		for (int i = 0; i < N;++i)
		if (!vis[i])
			cout << data[i] << " ";
		cout << "$" << endl;






	}





	return 0;
}