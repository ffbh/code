#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s;
int dfs(int pos){
	if (pos >= s.length())
		return -1;
	if (s[pos] >= 'p'&&s[pos] <= 'z')
		return pos+1;
	if (s[pos] == 'N')
		return dfs(pos + 1);
	else{
		pos = dfs(pos + 1);
		if (pos < 0)
			return pos;
		return dfs(pos);
	}
}



int main(){
	ifstream in("C:\\temp.txt");
	while (getline(cin, s)){
		int ans = dfs(0);
		if (ans == s.length())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}