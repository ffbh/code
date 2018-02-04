#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s;
bool Number(char c){
	return c >= '0'&&c <= '9';
}
int dfs(int pos){
	int time;
	while (pos < s.length()&&s[pos]!=')'){
		time = 0;
		while(Number(s[pos])){
			time = time * 10 + s[pos] - '0';
			pos++;
		}
		if (time == 0)
			time = 1;
		if (s[pos] >= 'a'&&s[pos] <= 'z'){
			while (time--)
				putchar(s[pos]);
			pos++;
		}
		else if (s[pos] == '('){
			int temp;
			while (time--)
				temp = dfs(pos + 1);
			pos = temp;
		}
	}
	return pos + 1;
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> s;
		
		dfs(0);
		cout << endl;
	}





	return 0;
}