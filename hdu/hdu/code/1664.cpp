#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
int vis[65540];
int N;
struct Node{
	int mod;
	string pace;
};
string bfs(int* Data,int num){
	queue<Node> qn;
	Node temp1, temp2;
	for (int i = 0; i <= N + 2;++i)
		vis[i] = 0;
	for (int i = 0; i < num; ++i)
	if(Data[i]){
		temp1.pace += char('0' + Data[i]);
		temp1.mod = Data[i] % N;
		vis[temp1.mod] = 1;
		qn.push(temp1);
	}
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (temp1.mod == 0)
			return temp1.pace;
		for (int i = 0; i < num; ++i){
			temp2 = temp1;
			temp2.mod = (temp2.mod * 10 + Data[i]) % N;
			temp2.pace += char(Data[i] + '0');
			if (!vis[temp2.mod]){
				vis[temp2.mod] = 1;
				qn.push(temp2);
			}
		}
	}
	return "";
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N&&N){
		bool flag = 1;
		int temp[3];
		string ans = "";
		for (int i = 1; i < 10; ++i){
			temp[0] = i;
			string t = bfs(temp, 1);
			if (t.length()){
				if (ans.length() == 0 || ans.length()>t.length())
					ans = t;
			}
		}
		if (ans.length()){
			cout << ans << endl;
			flag = 0;
		}
		if (flag){
			ans = "";
			for (int i = 0; i < 10; ++i)
			for (int j = i + 1; j < 10; ++j){
				temp[0] = i;
				temp[1] = j;
				string t = bfs(temp, 2);
				if (t.length()){
					if (ans.length() == 0 || ans.length()>t.length() || ans.length() == t.length()
						&& ans > t)
						ans = t;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}

