#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s;
int N;
int num;
void dfs(int pre,int pos,bool flag){
	if (pos == s.length()){
		if (pre == N)
			num++;
		return;
	}
	int now = 0;
	for (int i = pos; i < s.length(); ++i){
		now = now * 10 + s[i] - '0';
		if (flag)
			dfs(pre - now, i + 1, 1);
		dfs(pre + now, i + 1, 1);
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> s >> N){
		num = 0;
		dfs(0, 0, 0);
		cout << num << endl;


	}
	return 0;
}