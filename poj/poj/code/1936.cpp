#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s, t;
bool dfs(int a, int b){
	if (a == s.length())
		return 1;
	for (int i = b; i < t.length();++i)
	if (s[a] == t[i]){
		if (dfs(a + 1, i + 1))
			return 1;
		else
			return 0;
	}
	return 0;
}



int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> s >> t){
		if (s.length() > t.length())
			cout << "No" << endl;
		else if (dfs(0, 0))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;




	}





	return 0;
}