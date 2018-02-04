#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
string num[10010];
string temp;
bool dfs(int pos1, int pos2, int k){
	if (pos2 == temp.length())
		return pos1 == num[k].length();
	if (temp[pos2] == '?')
		return dfs(pos1 + 1, pos2 + 1, k);
	else if (temp[pos2] != '*')
		return num[k][pos1] == temp[pos2] && dfs(pos1 + 1, pos2 + 1, k);
	else{
		for (int i = pos1; i <= num[k].length();++i)//////////
		if (dfs(i, pos2 + 1, k))
			return 1;
	}
	
	return 0;

 }


int main(){
	ifstream in("C:\\temp.txt");
	while (in >> N >> M){
		for (int i = 1; i <= N; ++i)
			in >> num[i];
		while (M--){
			in >> temp;
			int ans = 0;
			for (int i = 1; i <= N;++i)
			if (dfs(0, 0, i))
				ans++;
			if (ans)
				cout << ans << endl;
			else
				cout << "Not match" << endl;
		}
	}
	return 0;
}