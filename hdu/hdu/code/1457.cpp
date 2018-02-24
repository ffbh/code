#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string data[60];
int vis[60];

int main(){
	ifstream in("C:\\temp.txt");
	int K;
	while (cin >> K&&K){
		for (int i = 1; i <= 52; ++i)
			cin >> data[i];
		memset(vis, 0, sizeof(vis));
		int num = 1;
		int temp = 0;
		K++;
		for (int i = 52; num<=52; --i){
			if (i == 0)
				i = 52;
			if (!vis[i]){
				temp++;
				if (temp == K){
					temp = 0;
					vis[i] = num++;
				}
			}
		}
		for (int i = 1; i <= 52;++i)
		if (vis[i] == 52){
			cout << data[i] << endl;
			break;
		}
	}
	return 0;
}