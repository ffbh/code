#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N;
string ans[10];
bool vis[10];
set<string> vs;
set<string > V;
string s;
int num;
bool mark[10];
void dfs(string t, int index){
	if (index == num){
		sort(t.begin(), t.end());
		vs.insert(t);
		return;
	}

	for (int i = 0; i < s.length(); ++i){
		if (mark[i])
			continue;
		mark[i] = true;
		dfs(t + s[i], index + 1);
		mark[i] = false;
	}
}

void getAll(int n){
	vs.clear();
	memset(mark, 0, sizeof(mark));
	s = "";
	for (int i = 1; i <= N; ++i)
	if (!vis[i])
		s += '0' + i;
	num = n;

	dfs("", 0);
}


void DFS(int index, int rest){
	if (rest == 0){
		string str = "";
		for (int i = 0; i < index - 1; ++i)
			str += ans[i] + '-';
		str += ans[index - 1];
		V.insert(str);
		return;
	}
	for (int i = 1; i <= rest; ++i){
		getAll(i);
		set<string>  temp = vs;
		set<string>::iterator it = temp.begin();
		for (; it != temp.end(); ++it){
			ans[index] = *it;
			for (int k = 0; k < ans[index].length(); ++k)
				vis[ans[index][k] - '0'] = 1;
			DFS(index + 1, rest - i);

			for (int k = 0; k < ans[index].length(); ++k)
				vis[ans[index][k] - '0'] = 0;

		}

	}


}










int main(){
	ifstream in("C:\\input.txt");
	cin >> N;


	V.clear();
	DFS(0, N);
	set<string>::iterator it = V.begin();
	for (; it != V.end();++it){
		printf("%s\n", (*it).c_str());

	}


	return 0;
}