#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	string s;
	bool vis[210];
	while (getline(cin, s)){
		memset(vis, 0, sizeof(vis));
		string temp = "";
		for (int i = 0; i < s.length();++i)
		if (s[i] != ' ')
			temp += s[i];
		for (int i = 2; i < temp.length(); i += 3){
			putchar(temp[i]);
			vis[i] = 1;
		}
		for (int i = 1; i < temp.length(); i += 2)
		if (!vis[i]){
			vis[i] = 1;
			putchar(temp[i]);
		}
		for (int i = 0; i < temp.length();++i)
		if (!vis[i])
			putchar(temp[i]);
		cout << endl;

	}





	return 0;
}