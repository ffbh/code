#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N;
_int64 num[110];
_int64 K;
_int64 fun(string& s){
	_int64 temp = 0;
	for (int k = 0; k < s.length(); ++k)
		temp = temp * 2 + s[k] - '0';
	return temp;
}

bool dfs(_int64 pre,int pos){
	if (pre == K)
		return 1;
	if (pos == N)
		return 0;
	return dfs(pre, pos + 1) || dfs(pre^num[pos], pos + 1);
}



int main(){
	ifstream in("C:\\temp.txt");
	int M;
	while (cin >> M >> N){
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			num[i] = fun(s);
		}
		cin >> M;
		while (M--){
			string s1, s2;
			cin >> s1 >> s2;
			K = fun(s2);
			if (dfs(fun(s1),0))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}